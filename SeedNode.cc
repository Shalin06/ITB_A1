#include <omnetpp.h>
#include <bits/stdc++.h>
#include "message_m.h"
using namespace omnetpp;


class Seed :public cSimpleModule {
protected:
    int number_of_seeds;
    int number_of_peers;
    std:: unordered_map<int,int> peer_map;
    std::unordered_map<int,bool> dead_map;
    vector peer_list;
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void handleAddPeerRequest(cMessage *msg);
    virtual void handleDeadMessage(cMessage *msg);
};

Define_Module(Seed);

void Seed :: initialize(){

    number_of_seeds = getParentModule()->par("number_of_seeds");
    number_of_peers = getParentModule()->par("number_of_peers");
    setGateSize("g", number_of_peers);
    EV << number_of_seeds << std::endl;
}

void Seed :: handleMessage(cMessage *msg) {
    if(auto AddPeerReq = dynamic_cast<AddPeerToSeedRequest*>(msg)){
        handleAddPeerRequest(msg);
    }
    if(auto deadMsg = dynamic_cast<Dead*>(msg)){
        handleDeadMessage(msg);
    }
}

void Seed :: handleAddPeerRequest(cMessage *msg){

    auto AddPeerReq = dynamic_cast<AddPeerToSeedRequest*>(msg);

    int gate_ind = msg->getArrivalGate()->getIndex();
    int sender= msg->getSenderModule()->getIndex();
    peer_map[sender] = AddPeerReq->getPeer_ind();

    int sender_gate_ind = msg->getSenderGate()->getIndex();
    cModule *senderModule = msg->getSenderModule();

    gate("g$o",gate_ind)->connectTo(senderModule->gate("g$i",sender_gate_ind));

    peer_list.push(senderModule->getIndex());
    AddPeerToSeedReply *reply_message = new AddPeerToSeedReply();
    reply_message->setPeer_ind(senderModule->getIndex());
    reply_message->setSeed_ind(getIndex());
    reply_message->setPeer_list(peer_list);
    send(reply_message,gate("g$o",gate_ind));

}

void Seed:: handleDeadMessage(cMessage* msg){
    EV << "Recieved Dead Message"<<endl;
    auto dead_msg = dynamic_cast<Dead*>(msg);
    dead_map[dead_msg->getPeer_ind()] = true;
    auto it = peer_map.find(dead_msg->getPeer_ind());
    peer_map.erase(it);
    peer_list.remove(dead_msg->getPeer_ind());
}
