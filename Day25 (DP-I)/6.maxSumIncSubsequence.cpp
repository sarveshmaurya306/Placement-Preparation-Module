#include<bits/stdc++.h>
using namespace std;

//! on gfg

class Solution{
	public:
	int solve(int *arr, int ind, int pre, int last, vector<vector<int>> &dp){
	    if(ind>=last) return 0;
	    if(dp[ind][pre+1]!=-1) return dp[ind][pre+1];
	    
	    int maxi=0;
	    if(pre==-1 || arr[ind] > arr[pre])
	        maxi=max(maxi, arr[ind] + solve(arr, ind+1, ind, last, dp));
	    
	    dp[ind][pre+1]=maxi= max(maxi, solve(arr, ind+1, pre, last, dp));
	    return maxi;
	}
	
	int maxSumIS(int arr[], int n){
	    vector<vector<int>> dp(n, vector<int>(n+1, -1));
	    return solve(arr, 0, -1, n, dp);
	}  
};