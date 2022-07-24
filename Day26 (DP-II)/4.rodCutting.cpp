#include<bits/stdc++.h>
using namespace std;


class Solution {
public:    
    int dp[102][102];
    
    int solve(vector<int> & cuts, int start, int end, int cut_startInd, int cut_endInd){
        if(cut_startInd> cut_endInd) return 0;
        
        if(dp[cut_startInd][cut_endInd]!=-1) return dp[cut_startInd][cut_endInd];
        
        int mini=INT_MAX;
        
        for(int i=cut_startInd;i<=cut_endInd;i++){
            int temp=  solve(cuts, start, cuts[i], cut_startInd, i-1) + solve(cuts, cuts[i], end, i+1, cut_endInd) + (end-start);
            //start-> cut[i] + cut[i]-> end + cost;
            
            mini= min(temp, mini);
        }
        
        return dp[cut_startInd][cut_endInd]=mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        return solve(cuts, 0, n, 0, cuts.size()-1);
    }
};