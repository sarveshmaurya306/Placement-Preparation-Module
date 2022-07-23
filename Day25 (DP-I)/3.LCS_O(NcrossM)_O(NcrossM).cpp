class Solution {
public:
//     int solve(string &a, int i, string &b, int j){
//         if(i<0 || j<0) return 0;
//         if(a[i]==b[j])
//             return 1+solve(a, i-1, b, j-1);
//         return max(solve(a, i-1, b, j), solve(a, i, b, j-1));
//     }
    
    int longestCommonSubsequence(string a, string b) {
        int m=a.size(), n=b.size();
        // return solve(a, m-1, b, n-1);
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        
        return dp[m][n];
    }
};