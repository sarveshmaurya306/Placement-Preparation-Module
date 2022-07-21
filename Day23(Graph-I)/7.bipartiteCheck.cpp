#include<bits/stdc++.h>
using namespace std;

#define pb push_back
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<vector<int>> adj(n);
        
        for(int u=0;u<n;u++){
            for(int i=0;i<graph[u].size();i++){
                int v= graph[u][i];
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        
        vector<int> color(n, 0);
        vector<int> vis(n, false);
        
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            
            color[i]=1;
            if(!check(adj, color, i, 1, vis)) return false;
            color[i]=0;
        }
        
        return true;
    }
    
    bool check(vector<vector<int>>& adj, vector<int> &color, int curr, int srcColor, vector<int> &vis){
        int n= adj.size();
        if(curr>=n) return true;
        
        if(vis[curr] && color[curr]==srcColor)  return true;
        if(vis[curr] && color[curr]!=srcColor) return false;
        
        color[curr]=srcColor;
        
        vis[curr]=true;
        
        for(int relV: adj[curr]){
            if(!check(adj, color, relV, 1-srcColor, vis)) return false;
        }
        return true;
    }
};