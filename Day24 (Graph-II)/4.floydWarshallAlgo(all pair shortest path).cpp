#include<bits/stdc++.h>
using namespace std;

//!on coding ninjas

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>> dis(n+1, vector<int>(n+1, 1e9));

    //floyd warshall start
    //initial condition -> let's assume theire is only one minimum edge b/w u->v ie., wt;
    for(int i=0;i<edges.size();i++){
        int u= edges[i][0], v=edges[i][1], wt=edges[i][2];
        dis[u][v]=wt; //for bidirection

        dis[u][u]=dis[v][v]=0;
    }

    for(int k=1;k<=n;k++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                // u->v using (0,1,2...k) vertex;
                dis[u][v]=min(dis[u][v], dis[u][k]+dis[k][v]);
            }
        }
    }
	
    if(dis[src][dest]>1e7) dis[src][dest]=1e9;
    return dis[src][dest];
}