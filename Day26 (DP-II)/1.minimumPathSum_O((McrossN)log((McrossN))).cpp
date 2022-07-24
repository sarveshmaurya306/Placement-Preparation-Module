#include<bits/stdc++.h>
using namespace std;


#define ppi pair<int, pair<int,int>>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size(), n= grid[0].size();
        
        //to find min we use bfs
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;//sum, {i, j};
        pq.push({grid[0][0], {0, 0}});
        grid[0][0]=-1;
        
        while(!pq.empty()){
            auto top= pq.top(); pq.pop();
            int sum= top.first, i= top.second.first, j=top.second.second;
            if(i==m-1 && j==n-1) return sum;
            
            int down= i+1, right= j+1;
            if(down <m && grid[down][j]!=-1) {
                pq.push({sum+grid[down][j], {down, j}});
                grid[down][j]=-1;
            }
            if(right<n && grid[i][right]!=-1) {
                pq.push({sum+grid[i][right], {i, right}});
                grid[i][right]=-1;
            }
        }
        
        return -1;
    }
};