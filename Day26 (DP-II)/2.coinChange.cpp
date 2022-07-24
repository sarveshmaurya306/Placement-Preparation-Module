#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> dp;
    
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1, vector<int>(coins.size(), -1));
        int ans=solve(coins, amount, 0);
        return ans==1e6?-1:ans;
    }
    
    int solve(vector<int>& coins, int amount, int ind){
        if(amount==0) return 0;
        if(ind>=coins.size()) return 1e6;
        
        if(dp[amount][ind]!=-1) return dp[amount][ind];
        
        int a, b, c; a=b=c=1e6;
        
        if(amount-coins[ind] >=0){ //take not take
            a=1+ solve(coins, amount-coins[ind], ind);
            b=1+ solve(coins, amount-coins[ind], ind+1);
        } 
        //don't take
        c= solve(coins, amount, ind+1);
        return dp[amount][ind]=min({a, b, c});
    }
};