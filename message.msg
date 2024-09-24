cplusplus {{
#include <vector>
#include <bits/stdc++.h>

}}
class vector
{
	int32_t label[] @custom @sizeGetter(getNumLabels) @sizeSetter(setNumLabels);
}
cplusplus(vector) {{
    protected:
    std::vector<int32_t> labels;
    public:
        // expected methods:
        virtual void setNumLabels(size_t size) {labels.resize(size);}
        virtual size_t getNumLabels() const {return labels.size();}
        virtual int32_t getLabel(size_t k) const {return labels.at(k);}
        virtual void setLabel(size_t k, int32_t label) {labels.at(k) = label;}
        // new methods:
        virtual void push(int32_t label) {labels.push_back(label);}
        virtual int32_t pop() {auto l=labels.back();labels.pop_back();return l;}
        virtual void remove(int32_t label) {
        	auto it = std::find(labels.begin(), labels.end(),label);
 
            if (it != labels.end()) {
                labels.erase(it);
            }
        }
}}
cplusplus(vector::copy) {{
    labels = other.labels;
}}

message AddPeerToSeedRequest{
    int peer_ind;
	int seed_ind;
	string msg;
}

message AddPeerToPeerRequest{
	int sender_peer_ind;
	int reciever_peer_ind;
}

message LivelinessRequest{
 	int timestamp;
 	int self_ind;
}

message LivelinessReply{
	int timestamp;
	int sender_peer_ind;
	int self_ind;
}

message Dead{
    int timestamp;
	int peer_ind;
	int seed_ind;
}

message AddPeerToSeedReply{
	int peer_ind;
	int seed_ind;
	vector peer_list;
}

message Gossip{
	int timestamp;
 	int sender_peer_ind;
 	string msg;
}

message Block{
	string previous_hash;
	string merkel_root;
	string timestamp;
}
