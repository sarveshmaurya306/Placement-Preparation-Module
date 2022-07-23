class Pair{
    int a, b;
    Pair(int a, int b){
        this.a= a;
        this.b=b;
    }
}

class Solution {
    int solve(List<Pair> ls, int i, int m, int n, int [][][]dp){
        if(i>=ls.size()) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        
        int maxi=0;
        if(ls.get(i).a<=m && ls.get(i).b<=n){
            maxi= Math.max(maxi, 1+solve(ls, i+1, m-ls.get(i).a, n-ls.get(i).b, dp));
        }
        return dp[i][m][n]=Math.max(maxi, solve(ls, i+1, m, n, dp));
    }
    
    public int findMaxForm(String[] strs, int m, int n) {
        int [][][]dp= new int[strs.length+1][m+1][n+1];
        
        for(int i=0;i<strs.length+1;i++)
            for(int j=0;j<m+1;j++)
                for(int k=0;k<n+1;k++)
                    dp[i][j][k]=-1;
        
        List<Pair> ls= new ArrayList<>();
        
        for(int i=0;i<strs.length;i++){
            int zero=0, one=0;
            
            for(int j=0;j<strs[i].length();j++){
                if(strs[i].charAt(j) =='0') zero++;
                else one++;
            }
            
            ls.add(new Pair(zero, one));
        }
        
        return solve(ls, 0, m, n, dp);
    }
}