#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*> &mp){
        if(mp.find(node)!=mp.end()) return mp[node];
        mp[node]= new Node(node->val);
        
        for(Node* relV: node->neighbors){
            Node* next= dfs(relV, mp); //jate time
            mp[node]->neighbors.push_back(next); //aane ke baad
        }
        return mp[node];
    }
    
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> mp;
        // mp[node]= new Node(node->val);
        //go to all the nodes and make connection;
        return dfs(node, mp);
    }
};