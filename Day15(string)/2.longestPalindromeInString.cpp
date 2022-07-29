class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i=0;i<n;i++) dp[i][i]=true; //filling 1 element as always pal
        
        int start=0, maxLen=1;
        
        for(int i=0;i<n-1;i++){ //filling two value;
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                start=i;
                maxLen=2;
            }
        }
        
        for(int k=3;k<=n;k++){ //length of pal
            for(int i=0;i<n-k+1;i++){ //row
                int j=i+k-1; //col
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    if(k>maxLen){
                        maxLen=k;
                        start=i;
                    }
                }
            }
        }
        
        return s.substr(start, maxLen);
        // return solve(s, 0, s.size()-1);
    }
    /*
    string solve(string &a, int i, int j){
        if(i>j) return "";
        
        if(dp.find(ind)!=dp.end()) return dp[ind];
        
        if(a[i]==a[j] && isPal(a, i+1, j-1))
            return dp[ind]= a.substr(i, j-i+1);
        
        string x=solve(a, i, j-1);
        string y=solve(a, i+1, j);
        return x.size()>y.size()?x:y;
    }
    
    bool isPal(string &s,int start,int end){
        while(start < end){
            if(s[start++] != s[end--]){return false;}
        }
        return true;
    }
    */
};