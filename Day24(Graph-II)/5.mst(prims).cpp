#include<bits/stdc++.h>
using namespace std;

//! gfg
// take smallest edge among all the taken vertex

class Solution{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adjj[]){
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i=0;i<V;i++){
            for(int j=0;j<adjj[i].size();j++){
                int u= i, v= adjj[i][j][0], wt= adjj[i][j][1];
                adj[u].push_back({v, wt});
            }
        }
        
        
        unordered_set<int> st;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        //choose 0th node;
        
        pq.push({0, 0});
        //wt-> node;

        int ans=0;
        while(!pq.empty()){
            int node= pq.top().second;
            int wt= pq.top().first; pq.pop();
            
            if(st.find(node)!=st.end()) continue;
            st.insert(node);
            
            ans+= wt;
            
            for(auto it: adj[node]){
                pq.push({it.second, it.first});
            }
        }
        
        return ans;
    }
};