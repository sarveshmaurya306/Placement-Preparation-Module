class Solution {
    
	//     int solve(String a, String b, int i, int j, int [][] dp){
	//         if(i==0) return j;
	//         if(j==0) return i;
	
	//         if(dp[i-1][j-1]!=-1) return dp[i-1][j-1];
	//         if(a.charAt(i-1)==b.charAt(j-1)){
	//             dp[i-1][j-1]=solve(a, b, i-1, j-1, dp);
	//             return dp[i-1][j-1];
	//         }
			
	//         int insert1= 1+solve(a, b, i-1, j, dp);
	//         int insert2= 1+solve(a, b, i, j-1, dp);
	//         //delete will act same as insert so no need to implement that
	//         int replace= 1+solve(a, b, i-1, j-1, dp);
			
	//         dp[i-1][j-1]=Math.min(replace, Math.min(insert1, insert2));
	//         return dp[i-1][j-1];
	//     }
		
		public int minDistance(String a, String b) {
			int m= a.length();
			int n= b.length();
			
			int [][] dp= new int[m+1][n+1];
			
			for(int i=0;i<=m;i++) dp[i][0]=i;
			for(int j=0;j<=n;j++) dp[0][j]=j;
			
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					if(a.charAt(i-1)==b.charAt(j-1))
						dp[i][j]=dp[i-1][j-1];
					else{
						int insert1= 1+dp[i-1][j];
						int insert2= 1+dp[i][j-1];
						//delete will act same as insert so no need to implement that
						int replace= 1+dp[i-1][j-1];
	
						dp[i][j]=Math.min(replace, Math.min(insert1, insert2));
					}
				}
			}
			
			return dp[m][n];
			
			// for(int i=0;i<m;i++)
			//     for(int j=0;j<n;j++)
			//         dp[i][j]=-1;
			
			// return solve(a, b, m, n, dp);
		}
	}