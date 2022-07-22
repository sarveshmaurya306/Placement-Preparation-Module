#include<bits/stdc++.h>
using namespace std;
//! on coding ninjas


vector<int> dijkstra(vector<vector<int>> &vec, int v, int e, int s) {
    // Write your code here.
    vector<vector<pair<int,int>>> adj(v);
    
    for(int i=0;i<e;i++){
       int vv= vec[i][0], u=vec[i][1], wt=vec[i][2];
        adj[u].push_back({vv, wt});
        adj[vv].push_back({u, wt});
    }
    
    vector<int> dis(v, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // dis-> node;
    pq.push({0, s});
    dis[s]=0;
    
    while(!pq.empty()){
        auto top= pq.top(); pq.pop();
        int curr_node=top.second;
        int curr_dis= top.first;
        
        for(auto it: adj[curr_node]){
            int relV= it.first;
            int wt= it.second;
            if(curr_dis+wt < dis[relV]){
                dis[relV]=curr_dis+wt;
                pq.push({dis[relV], relV});
            }
        }  
    }
    
    return dis;
}
