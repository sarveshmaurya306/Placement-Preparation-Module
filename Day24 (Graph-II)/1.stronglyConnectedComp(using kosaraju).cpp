#include<bits/stdc++.h>
using namespace std;

//!on coding ninjas

void topoSort(vector<vector<int>> &adj, int node, stack<int> &st, vector<bool >&vis){
    if(vis[node]) return;
    vis[node]=true;
       
    for(int relV: adj[node]){
        topoSort(adj, relV, st, vis);
    }
    
    st.push(node);
}

void dfs(vector<vector<int>> &revAdj, int node, vector<bool>&vis, vector<int>& tempAns){
    if(vis[node]) return ;
    vis[node]=true;
    tempAns.push_back(node);
    
    for(int relV: revAdj[node]){
        dfs(revAdj, relV, vis, tempAns);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges){
    vector<vector<int>> adj(n), revAdj(n);
    for(int i=0;i<edges.size();i++){
        int v= edges[i][0], u=edges[i][1];
        adj[v].push_back(u);
        revAdj[u].push_back(v);
    }
    
    //step 1 -> do topo sort
    stack<int> st;
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++)
        topoSort(adj, i, st, vis);
    
    //step 2-> reverse the edges;
    //stored in revAdj
    
    vector<vector<int>> ans;
    //step 3-> do dfs based on the topo sort on revAdj
    for(int i=0;i<n;i++) vis[i]=false;
    while(!st.empty()){
        int top= st.top(); st.pop();
        if(vis[top]) continue;
        vector<int> tempAns;
        dfs(revAdj, top, vis, tempAns);
        ans.push_back(tempAns);
    }
    
    return ans;
}
