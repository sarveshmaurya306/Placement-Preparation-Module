#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        //using kahn's algo;
        vector<int> in(n, 0);
        vector<vector<int>> adj(n);
        
        for(auto &it: pre){
            int u= it[0], v= it[1];
            adj[u].push_back(v);
            in[v]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
            if(in[i]==0) q.push(i);
        
        int initCnt=q.size();
        if(initCnt==0) return false; //no course can be taken
        
        while(!q.empty()){
            int top= q.front(); q.pop();
            for(int relV: adj[top]){
                if(--in[relV]==0) {
                    initCnt++;
                    q.push(relV);
                }
            }
        }
        
        return initCnt==n; //is all element came in queue or not;
    }
};