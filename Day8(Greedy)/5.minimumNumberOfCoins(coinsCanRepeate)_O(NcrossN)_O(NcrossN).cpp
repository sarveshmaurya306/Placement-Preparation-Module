#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	vector<vector<int>> dp;
	
	int solve(vector<int> &c, int v, int ind){
	    if(v==0) return 0;
	    if(v<0) return 1e5;
	    
	    if(ind>=c.size()) return 1e5;
	    
	    if(dp[ind][v]!=-1) return dp[ind][v];
	    
	    int a, b;
	    a=b=1e5;
	    
	    if(v-c[ind] >=0 ){
	        a= 1 + solve(c, v-c[ind], ind);
	        b= solve(c, v, ind+1);
	        return dp[ind][v]=min(a,b);
	    }
	    
	    b= solve(c, v, ind+1);
	    return dp[ind][v]=min(a, b);
	}
	
	int minCoins(int coins[], int n, int v){ 
	    vector<int> c; 
	    dp.resize(n+1, vector<int> (v+1, -1));
	    
	    for(int i=0;i<n;i++) c.push_back(coins[i]);
	    
	    sort(c.begin(), c.end(), greater<>());
	    
	    int ans= solve(c, v, 0);
	    return ans==1e5?-1:ans;
	} 
	  
};