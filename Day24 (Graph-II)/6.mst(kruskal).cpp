#include<bits/stdc++.h>
using namespace std;

//! on coding ninjas

//take the smallest edge always if form cycle then skip this edge;

#include<bits/stdc++.h>
#define ppi pair<int, pair<int, int>>

vector<int> rankk;
vector<int> par;

int findPar(int a){
    if(par[a]==a) return a;
    return par[a]=findPar(par[a]);
}

void unionn(int a, int b){
    a= findPar(a), b= findPar(b);
    if(rankk[a]<rankk[b])
        par[a]=b;
    else if(rankk[b]< rankk[a])
        par[b]=a;
    else
        par[b]=a, rankk[a]++;
}


int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    // Write your code here.
    n++;
    par.resize(n, 0);
    rankk.resize(n, 0);
    for(int i=0;i<n;i++) par[i]=i;
    
    priority_queue< ppi, vector<ppi>, greater<ppi> > pq;
    for(int i=0;i<m;i++){
        int u= graph[i][0], v= graph[i][1], wt=graph[i][2];
        pq.push({wt, {u, v}});
    }
    
    int cnt=0;
    while(!pq.empty()){
        auto top= pq.top(); pq.pop();
        int wt= top.first, u = top.second.first, v= top.second.second;
        if(findPar(u)!=findPar(v)){ //not belongs to same class ie., no cycle
            unionn(u, v);
            cnt+= wt;
        }
    }
    
    return cnt;
}