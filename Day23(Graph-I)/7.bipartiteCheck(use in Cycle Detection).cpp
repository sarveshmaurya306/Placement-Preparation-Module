#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> color;
    
    bool check(vector<vector<int>>& graph, int node){
        // color[node]=0;
        
        for(int relV: graph[node]){
            if(color[relV]==-1){ //not colored yet
                color[relV]=1-color[node];
                if(!check(graph, relV)) return false;
            } else{ //already colored;
                if(color[relV]==color[node]) return false;
                if(color[relV]!=color[node]) continue;
            }
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        color.resize(n, -1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!check(graph, i)) return false;
            }
        }
        
        return true;
    }
};