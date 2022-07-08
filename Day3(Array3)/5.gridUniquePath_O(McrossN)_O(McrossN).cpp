#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:    
    ll solve(int i, int j, int m, int n, vector<vector<ll>> &dp){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        ll down=solve(i+1, j, m, n, dp);
        ll right=solve(i, j+1, m, n, dp);
        
        return dp[i][j]=down+right;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<ll>> dp(101, vector<ll>(101, -1));
        return solve(0, 0, m, n, dp);
    }
};