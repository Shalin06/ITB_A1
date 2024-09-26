#include <omnetpp.h>
#include <bits/stdc++.h>
#include <ctime>
#include <fstream>
#include <sstream>
#include "message_m.h"
#include "config.h"
#include "SHA256.h"
#include "functional"
using namespace omnetpp;

std::vector<int> generateRandomArray(int n, int x) {
    if (n > x + 1) {
        throw std::invalid_argument("n cannot be greater than x + 1 when generating unique numbers.");
    }

    std::vector<int> arr(x);
    for (int i = 0; i < x; ++i) {
        arr[i] = i;
    }

    srand(time(0));
    std::random_shuffle(arr.begin(), arr.end());

    return std::vector<int>(arr.begin(), arr.begin() + n);
}

vector shuffle(vector arr, int x){
    std::vector<int> temp;
    for(int i = 0; i < arr.getNumLabels();i++){
        temp.push_back(arr.getLabel(i));
    }
    vector ans;
    srand(0);
    std::random_shuffle(temp.begin(), temp.end());
    int cnt = 0;
    for(int i = 0;i < temp.size() && cnt < 4;i++){
        if(temp[i] != x){
            ans.push(temp[i]);
            cnt++;
        }
    }
    return ans;
}

int generate_random_number(int n){
    srand(time(0));
    return rand()%n;
}

double randExp(double lambda) {
    double u = (double) rand() / RAND_MAX;
    return -log(1 - u) / lambda;
}

class Peer : public cSimpleModule {
protected:

    int tau;
    double hashing_power;
    int number_of_block_generated = 0;

    std::ofstream csvFile;
    std::fstream blockDataFile;


    int number_of_seeds;
    int number_of_peers;
    int message_count = 0;
    bool validation = true;

    std::unordered_map<std::string, int> seed_list;
    std::unordered_map<std::string, AddPeerToSeedRequest*> peerRequestMap;
    std::unordered_map<int,bool> peer_list;
    std::unordered_map<int,int> liveliness_cnt;
    std::set<std::string> block_list;
    std::queue<Block> pendingQueue;
    std::set<std::string> message_list;
    std::set<std::string> block_hashes;
    std::hash<std::string> hash_fn;
    std::string prev_block_hash;


    cMessage* LivelinessEvent;
    cMessage* GossipEvent;
    cMessage* BlockGeneration;
    cMessage* BlockEvent;


    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void handleInitialization(cMessage *msg);
    virtual void addPeertoSeed(cMessage *msg);
    virtual void addPeertoPeer(cMessage *msg);
    virtual void addPeerToPeerHandler(cMessage* msg);
    virtual void sendLivenessRequest(cMessage* msg);
    virtual void handleLivelinessRequest(cMessage* msg);
    virtual void handleLivelinessReply(cMessage* msg);
    virtual void sendGossip(cMessage* msg);
    virtual void handleGossip(cMessage* msg);
    virtual void sendDeadMessageToSeed(int peer_ind);
    virtual void handleBlockGeneration(cMessage * msg);
    virtual void handleBlockMessage(cMessage* msg);
    virtual void writeBlockToCSV(Block* block);
    virtual void tauGenerator();
    virtual void askForBlockList(cMessage* msg);
    virtual bool validateBlocks(std::vector<Block*> blocks);
    virtual void finish() override;


public:
    bool dead = false;
};

Define_Module(Peer);

void Peer::tauGenerator(){
    tau = 0;
    while(tau<=4){
        double lambda = hashing_power/INTER_ARRIVAL_TIME;
        tau = randExp(lambda);
    }
}

void Peer::initialize(int stage) {
    if(stage == 0){
        int ind = getIndex();
        hashing_power = hashPower[ind];
        simtime_t delay = uniform(ind, ind+5);
        scheduleAt(simTime() + delay, new cMessage("delayedInit"));
    }
}

void Peer::handleMessage(cMessage *msg){
    if(dead == false){
        if(strcmp(msg->getName(), "delayedInit") == 0){
            handleInitialization(msg);
        }
        else if(auto AddPeerReq = dynamic_cast<AddPeerToSeedRequest*>(msg)){
            addPeertoSeed(AddPeerReq);
        }
        else if(auto AddPeerRpl = dynamic_cast<AddPeerToSeedReply*>(msg)){
            addPeertoPeer(AddPeerRpl);
        }
        else if(auto AddPeertoPeerReq = dynamic_cast<AddPeerToPeerRequest*>(msg)){
            addPeerToPeerHandler(AddPeertoPeerReq);
        }
        else if(msg == LivelinessEvent && simTime().inUnit(SimTimeUnit::SIMTIME_S) <=  1000){
            sendLivenessRequest(msg);
            scheduleAt(simTime() + 13, LivelinessEvent);
        }
        else if(auto livelinessReply = dynamic_cast<LivelinessRequest*>(msg)){
            handleLivelinessRequest(livelinessReply);
        }
        else if(auto recieveLiveRelpy = dynamic_cast<LivelinessReply*>(msg)){
            handleLivelinessReply(recieveLiveRelpy);
        }
        else if(msg == GossipEvent &&  simTime().inUnit(SimTimeUnit::SIMTIME_S) <=  1000){
            sendGossip(msg);
            scheduleAt(simTime()+5, GossipEvent);
        }
        else if(auto gossip = dynamic_cast<Gossip*>(msg)){
            handleGossip(gossip);
        }
        else if(msg == BlockGeneration && simTime().inUnit(SimTimeUnit::SIMTIME_S) <=  1000){
            handleBlockGeneration(msg);
        }
        else if(auto block = dynamic_cast<Block*>(msg)){
            handleBlockMessage(msg);
        }
        else if(msg == BlockEvent && simTime().inUnit(SimTimeUnit::SIMTIME_S) <=  1000){
            askForBlockList(msg);
        }
        else{
            std::cout<<msg->getName()<<std::endl;
            std::cout.flush();
        }
    }
}

void Peer::handleInitialization(cMessage* msg){
    int self_ind = getIndex();
    number_of_seeds = getParentModule()->par("number_of_seeds");
    setGateSize("g", 100);
    std::vector<int> seeds_to_connect = generateRandomArray(number_of_seeds / 2 + 1, number_of_seeds);
    for (auto i : seeds_to_connect) {

        std::string path = (std::string)getParentModule()->getFullName() + ".seeds[" + std::to_string(i) + "]";
        cModule *module = getModuleByPath(path.c_str());

        gate("g$o", i)->connectTo(module->gate("g$i", self_ind));

        AddPeerToSeedRequest *PeerRequestToSeed = new AddPeerToSeedRequest();
        PeerRequestToSeed->setPeer_ind(self_ind);
        PeerRequestToSeed->setSeed_ind(i);

        seed_list[module->getFullName()] = i;
        peerRequestMap[module->getFullName()] = PeerRequestToSeed;

        scheduleAt(simTime()+ 5, PeerRequestToSeed);
    }
    LivelinessEvent = new cMessage("Liveliness");
    GossipEvent = new cMessage("Gossip");
    BlockGeneration = new cMessage("Block Generation");
    BlockEvent = new cMessage("Block");

    char fileName[30];
    std::sprintf(fileName, "block_data%d.csv", self_ind);
    csvFile.open(fileName, std::ios::out | std::ios::app);

    if (csvFile.tellp() == 0) {
        csvFile << "Block_Hash,Time,Number_of_Blocks_Generated\n";
    }



    scheduleAt(simTime() + 13, LivelinessEvent);
    scheduleAt(simTime() + 5, GossipEvent);
    scheduleAt(simTime() + 5, BlockEvent);
}

void Peer:: addPeertoSeed(cMessage *msg){
    for(const auto &entry: peerRequestMap){
        auto AddPeerReq = dynamic_cast<AddPeerToSeedRequest*>(msg);
        if(AddPeerReq == entry.second){

            int seedIndex = AddPeerReq->getSeed_ind();
            send(AddPeerReq, "g$o", seedIndex);

            return;
        }
    }
}

void Peer:: addPeertoPeer(cMessage *msg){
    auto seed_reply = dynamic_cast<AddPeerToSeedReply*>(msg);
    vector peers = seed_reply->getPeer_list();
    peers = shuffle(peers,getIndex());


    int size = peers.getNumLabels();
    for(int i = 0;i < size;i++){
        auto peerConnectReq = new AddPeerToPeerRequest();
        peerConnectReq->setSender_peer_ind(getIndex());
        peerConnectReq->setReciever_peer_ind(peers.getLabel(i));

        if(peer_list.find(peers.getLabel(i)) == peer_list.end()){
            int gate_ind = number_of_seeds + peers.getLabel(i) + 1;

            std::string path = (std::string)getParentModule()->getFullName() + ".peers[" + std::to_string(peers.getLabel(i)) + "]";

            cModule* module = getModuleByPath(path.c_str());
            EV<< module->getFullName() << " "<< gate_ind << endl;


            gate("g$o", gate_ind)->connectTo(module->gate("g$i", number_of_seeds + getIndex() + 1));

            peer_list[peers.getLabel(i)] = true;

            send(peerConnectReq,gate("g$o",gate_ind));
        }
    }
    EV<< endl;
}

void Peer::addPeerToPeerHandler(cMessage* msg){

    int gate_ind = msg->getArrivalGate()->getIndex();

    cModule* module = msg->getSenderModule();

    gate("g$o",gate_ind)->connectTo(module->gate("g$i", number_of_seeds + getIndex() + 1));

    peer_list[module->getIndex()] = true;

}

void Peer::sendLivenessRequest(cMessage* msg){

    auto livelinessReq = new LivelinessRequest();
    livelinessReq->setTimestamp(simTime().inUnit(SimTimeUnit::SIMTIME_S));
    livelinessReq->setSelf_ind(getIndex());
    for(auto peer: peer_list){
        send(livelinessReq->dup(),gate("g$o",number_of_seeds + peer.first + 1));
        liveliness_cnt[peer.first]++;
        if(liveliness_cnt[peer.first] >= 4){
            sendDeadMessageToSeed(peer.first);
        }
    }
}

void Peer::handleLivelinessRequest(cMessage* msg){
    auto req = dynamic_cast<LivelinessRequest*>(msg);
    auto livelinessReply = new LivelinessReply();
    livelinessReply->setTimestamp(req->getTimestamp());
    livelinessReply->setSender_peer_ind(req->getSelf_ind());
    livelinessReply->setSelf_ind(getIndex());

    send(livelinessReply,gate("g$o", msg->getArrivalGate()->getIndex()));

    int n = generate_random_number(number_of_peers);
//    if(getIndex() == n){
//        dead = true;
//        auto deadMessage = new Dead();
//        for(auto i: seed_list){
//            deadMessage->setTimestamp(simTime().inUnit(SimTimeUnit::SIMTIME_S));
//            deadMessage->setPeer_ind(getIndex());
//            deadMessage->setSeed_ind(i.second);
//            send(deadMessage,gate("g$o",i.second));
//        }
//    }

}

void Peer::handleLivelinessReply(cMessage* msg){
    EV<<getFullName()<< "<------>" << msg->getSenderModule()->getFullName() <<endl;
    int sender_ind = msg->getSenderModule()->getIndex();
    liveliness_cnt[sender_ind]--;
}

void Peer::sendGossip(cMessage* msg){
    if(message_count > 10){
        cancelEvent(GossipEvent);
        return;
    }
    auto gossip = new Gossip();
    gossip->setTimestamp(simTime().inUnit(SimTimeUnit::SIMTIME_S));
    gossip->setSender_peer_ind(getIndex());
    gossip->setMsg("Gossip");
    message_count++;
    std::string msg_str = std::to_string(gossip->getTimestamp()) + std::to_string(gossip->getSender_peer_ind()) + gossip->getMsg(); 
    message_list.insert(msg_str);
    for(auto peer: peer_list){
        send(gossip->dup(),gate("g$o",number_of_seeds + peer.first + 1));
    }
}

void Peer::handleGossip(cMessage* msg){
    // EV<<getFullName()<< "<---Gossip--->" << msg->getSenderModule()->getFullName() <<endl;
    EV<< "Gossip Received: " << msg->getFullName() <<endl;
    auto gossip = dynamic_cast<Gossip*>(msg);
    std::string msg_str = std::to_string(gossip->getTimestamp()) + std::to_string(gossip->getSender_peer_ind()) + gossip->getMsg(); 
    if(message_list.find(msg_str) == message_list.end()){
        message_list.insert(msg_str);
        for(auto peer: peer_list){
            send(gossip->dup(),gate("g$o",number_of_seeds + peer.first + 1));
        }
    }
}

void Peer::sendDeadMessageToSeed(int peer_ind){
    for(auto i: seed_list){
        auto deadMessage = new Dead();
        deadMessage->setTimestamp(simTime().inUnit(SimTimeUnit::SIMTIME_S));
        deadMessage->setPeer_ind(peer_ind);
        deadMessage->setSeed_ind(i.second);
        send(deadMessage,gate("g$o",i.second));
    }
}
//
void Peer::handleBlockGeneration(cMessage* msg){
    auto block = new Block("new block");

    SHA256 sha256;
    std::string new_block_hash = std::to_string(hash_fn(prev_block_hash + std::to_string(getIndex())));
    sha256.update(new_block_hash);
    std::array<uint8_t, 32> digest = sha256.digest();
    new_block_hash = SHA256::toString(digest);
    block->setPrevious_hash(new_block_hash.c_str());
    block->setTimestamp(std::to_string(simTime().inUnit(SimTimeUnit::SIMTIME_S)).c_str());
    block->setMerkel_root("0");


    number_of_block_generated++;
    block_list.insert(block->getPrevious_hash());


    EV << new_block_hash.c_str() <<endl;


    for(auto peer: peer_list){
        EV<< "Sending Block to: " << peer.first<< "from: "<<getIndex() <<endl;
        send(block->dup(),gate("g$o",number_of_seeds + peer.first + 1));
    }
    writeBlockToCSV(block);
    tauGenerator();
    scheduleAt(simTime() + tau, BlockGeneration);
}

void Peer::handleBlockMessage(cMessage* msg){
    auto block = dynamic_cast<Block*>(msg);
    if(block_list.find(block->getPrevious_hash() ) == block_list.end()){
        cancelEvent(BlockGeneration);
        writeBlockToCSV(block);
        block_list.insert(block->getPrevious_hash());
        tauGenerator();
        scheduleAt(simTime() + tau, BlockGeneration);
        for(auto peer: peer_list){
            send(block->dup(),gate("g$o",number_of_seeds + peer.first + 1));
        }
    }
}

void Peer::askForBlockList(cMessage* msg){
    // Read all block from block_data.csv and validate them
    std::string file_name = "blockData.csv";
    if(peer_list.size() > 0){
        file_name = "block_data" + std::to_string(peer_list.begin()->first) + ".csv";
    }
    std::ifstream blockDataFile(file_name.c_str());
    std::string line;
    std::vector<Block*> blocks;
    while (std::getline(blockDataFile, line)) {

        std::stringstream ss(line);
        std::string block_hash, merkel_root, timestamp;
        std::getline(ss, block_hash, ',');
        std::getline(ss, merkel_root, ',');
        std::getline(ss, timestamp, ',');

        if(block_hash=="Block_Hash"){
            continue;
        }

        Block* block = new Block();
        block->setPrevious_hash(block_hash.c_str());
        block->setTimestamp(timestamp.c_str());
        block->setMerkel_root(merkel_root.c_str());
        blocks.push_back(block);
        prev_block_hash = block_hash;
        writeBlockToCSV(block);
    }
    // bool val = validateBlocks(blocks);
    tauGenerator();
    EV<< "tau: "<< tau <<endl;
    scheduleAt(simTime() + tau, BlockGeneration);
}

bool Peer::validateBlocks(std::vector<Block*> blocks) {
    for(auto block: blocks) {
        // Validate the block
        std::string block_hash = block->getPrevious_hash();
        std::string timestamp = block->getTimestamp();
        if(block_hashes.find(block_hash) == block_hashes.end()){
            block_hashes.insert(block_hash);
        }
        else{
            return false;
        }
    }
    validation = false;
    return true;
}
//void difference_in_seconds(std::string timestamp1, std::string timestamp2) {
//    std::tm tm1 = {};
//    std::tm tm2 = {};
//    std::istringstream ss1(timestamp1);
//    std::istringstream ss2(timestamp2);
//    ss1 >> std::get_time(&tm1, "%Y-%m-%d %H:%M:%S");
//    ss2 >> std::get_time(&tm2, "%Y-%m-%d %H:%M:%S");
//    std::time_t time1 = std::mktime(&tm1);
//    std::time_t time2 = std::mktime(&tm2);
//    return std::difftime(time1, time2);
//}
void Peer::writeBlockToCSV(Block* block) {
    // Write block data in CSV format: PeerID, BlockID, Time, Number_of_Blocks_Generated
    csvFile.seekp(0, std::ios::end);
    csvFile << block->getPrevious_hash() << ","
            << simTime() << ","
            << number_of_block_generated << "\n";
    csvFile.flush();
    prev_block_hash = block->getPrevious_hash();
}
void Peer::finish() {
    // Close the CSV file after the simulation
    if (csvFile.is_open()) {
        csvFile.close();
    }
    if (blockDataFile.is_open()) {
        blockDataFile.close();
    }
}
