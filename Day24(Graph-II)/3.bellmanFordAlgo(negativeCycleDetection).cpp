#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dis(V, 1e8);
        dis[S]=0;
        
        for(int i=0;i<V;i++){
            for(auto &it: adj){
                int u= it[0], v= it[1], wt=it[2];
                if(dis[u]+wt < dis[v]){
                    dis[v]=dis[u]+wt;
                }
            }
        }
		
        for(int i=0;i<V;i++)
            if(dis[i]>1e6) dis[i]=1e8;
            
        return dis;
    }
};
