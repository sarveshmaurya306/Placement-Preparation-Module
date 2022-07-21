#include<bits/stdc++.h>
using namespace std;

//! gfg

class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	void topoSort(int node, vector<int> adj[], vector<bool>&vis, stack<int>&st){
	    if(vis[node]) return;
	    vis[node]=true;
	    
	    for(int relV: adj[node]){
	        topoSort(relV, adj, vis, st);
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    stack<int> st;
	    vector<bool> vis(V, false);
	    vector<int> ans;
	    
	    for(int i=0;i<V;i++){
	        topoSort(i, adj, vis, st);
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top()); st.pop();
	    }
	    return ans;
	}
};