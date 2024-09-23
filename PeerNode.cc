#include <omnetpp.h>
#include <bits/stdc++.h>
#include <ctime>
#include <fstream>
#include <sstream>
#include "message_m.h"
#include "config.h"
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

    int number_of_seeds;
    int number_of_peers;
    int message_count = 0;


    std::unordered_map<std::string, int> seed_list;
    std::unordered_map<std::string, AddPeerToSeedRequest*> peerRequestMap;
    std::unordered_map<int,bool> peer_list;
    std::unordered_map<int,int> liveliness_cnt;
    std::set<Block*> block_list;
    std::queue<Block> pendingQueue;
    std::set<Gossip*> message_list;


    cMessage* LivelinessEvent;
    cMessage* GossipEvent;
    cMessage* Timer;


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
    virtual void handleTimer(cMessage * msg);
    virtual void handleBlockMessage(cMessage* msg);
    virtual void writeBlockToCSV(Block* block);
    virtual void tauGenerator();
    virtual void finish() override;


public:
    bool dead = false;
};

Define_Module(Peer);

void Peer::tauGenerator(){
    double lambda = hashing_power/INTER_ARRIVAL_TIME;
    tau = randExp(lambda);
}

void Peer::initialize(int stage) {
    if(stage == 0){
        int ind = getIndex();
        hashing_power = hashPower[ind];
        simtime_t delay = uniform(ind, ind+5);
        scheduleAt(simTime() + delay, new cMessage("delayedInit"));
    }
}

void Peer::handleMessage(cMessage *msg) {
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
        else if(msg == Timer && simTime().inUnit(SimTimeUnit::SIMTIME_S) <=  1000){
            handleTimer(msg);
        }
        else if(auto block = dynamic_cast<Block*>(msg)){
            handleBlockMessage(msg);
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
    Timer = new cMessage("Timer");
    tauGenerator();

    char fileName[30];
    std::sprintf(fileName, "block_data%d.csv", self_ind);
    csvFile.open(fileName, std::ios::out | std::ios::app);

    if (csvFile.tellp() == 0) {
        csvFile << "PeerID,BlockID,Time,Number_of_Blocks_Generated\n";
    }



    scheduleAt(simTime() + 13, LivelinessEvent);
    scheduleAt(simTime() + 5, GossipEvent);
    scheduleAt(simTime() + tau, Timer);
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
    for(auto peer: peer_list){
        send(gossip->dup(),gate("g$o",number_of_seeds + peer.first + 1));
    }
}

void Peer::handleGossip(cMessage* msg){
    EV<<getFullName()<< "<---Gossip--->" << msg->getSenderModule()->getFullName() <<endl;
    auto gossip = dynamic_cast<Gossip*>(msg);
    if(message_list.find(gossip) == message_list.end()){
        message_list.insert(gossip);
        for(auto peer: peer_list){
            send(gossip->dup(),gate("g$o",number_of_seeds + peer.first + 1));
        }
    }
    else{
        return;
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
void Peer::handleTimer(cMessage* msg){
        // generate block and broadcast;
    auto block = new Block("new block");
//        check if it is genesis or not;
    number_of_block_generated++;
    writeBlockToCSV(block);
    for(auto peer: peer_list){
        send(block->dup(),gate("g$o",number_of_seeds + peer.first + 1));
    }
    tauGenerator();
    scheduleAt(simTime()+tau, Timer);
}

void Peer::handleBlockMessage(cMessage* msg){
    cancelEvent(Timer);
    auto block = dynamic_cast<Block*>(msg);
    if(block_list.find(block) != block_list.end()){

    }
    tauGenerator();
    scheduleAt(simTime() + tau, Timer);
}

void Peer::writeBlockToCSV(Block* block) {
    // Write block data in CSV format: PeerID, BlockID, Time, Number_of_Blocks_Generated
    csvFile <<getIndex() << ","
            << block->getName() << ","
            << simTime() << ","
            << number_of_block_generated << "\n";
}
void Peer::finish() {
    // Close the CSV file after the simulation
    if (csvFile.is_open()) {
        csvFile.close();
    }
}
