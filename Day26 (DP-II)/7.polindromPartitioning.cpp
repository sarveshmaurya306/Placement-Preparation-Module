//! on gfg


class Solution{
public:
    bool isPal(string& s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    int dp[501][501];
    
    int solve(string& s, int start, int end){
        if(start>=end) return 0;
        
        if(isPal(s, start, end)) return dp[start][end]= 0;
        if(dp[start][end]!=-1) return dp[start][end];
        
        int mini=INT_MAX;
        for(int k=start;k<end;k++){
            int left, right;
            
            if(dp[start][k]!=-1)
                left= dp[start][k];
            else left= solve(s, start, k);
            
            if(dp[k+1][end]!=-1)
                right= dp[k+1][end];
            else right= solve(s, k+1, end);
            
            dp[start][k]=left;
            dp[k+1][end]=right;
            
            mini= min({left+right, mini});
        }
        
        return dp[start][end]=mini+1;
    }

    int palindromicPartition(string str){
        memset(dp, -1, sizeof(dp));
        return solve(str, 0, str.size()-1);
    }
};