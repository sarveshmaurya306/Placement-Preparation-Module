#include<bits/stdc++.h>
using namespace std;

//! on gfg

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        
        while(!q.empty()){
            int sz= q.size();
            for(int i=0;i<sz;i++){
                int top= q.front(); q.pop();
                ans.push_back(top);
                for(int relV: adj[top]){
                    if(!vis[relV]){
                        vis[relV]=true;
                        q.push(relV);
                    }
                }
            }
        }
        return ans;
    }
};