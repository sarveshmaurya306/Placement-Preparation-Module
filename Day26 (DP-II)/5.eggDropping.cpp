class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    vector<int> dp;
    int solve(int n, int k){
        if(k==0 || k==1) return k;
        if(n==1) return k;
        
        if(dp[k]!=-1) return dp[k];
        int mini= INT_MAX;
        for(int x=1;x<=k;x++){
            int temp= 1+ max(solve(n-1, x-1), solve(n, k-x));
            mini= min(mini, temp);
        }
        return dp[k]=mini;
    }
    
    int eggDrop(int n, int k){
        dp.resize(k+1, -1);
        return solve(n, k);
    }
};