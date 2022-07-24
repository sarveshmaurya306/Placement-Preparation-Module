class Solution {
//     int solve(int []nums, int i, int target, int [][] dp){
//         if(i==0) return 0;
//         if(target==0) return 1;
//         if(dp[i][target]!=-1) return dp[i][target];
        
//         if(target-nums[i-1]>=0){
//             int a= solve(nums, i-1, target-nums[i-1], dp);
//             if(a==1) return dp[i][target]=1;
//             return dp[i][target]=solve(nums, i-1, target, dp);
//         }
//         return dp[i][target]=solve(nums, i-1, target, dp);
//     }
    
    public boolean canPartition(int[] nums) {
        int sum= 0;
        int n= nums.length;
        for(int i: nums) sum+=i;
        
        if(sum%2!=0) return false;
        int s= sum/2;
        int dp[][]= new int[n+1][s +1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<s+1;j++){
                dp[i][j]=-1;
            }
        }
        
        for(int target=s;target>=0; target--) dp[0][target]=0;
        for(int i=0;i<n+1;i++) dp[i][0]=1;
        
        for(int i=1;i<n+1;i++){
            for(int target=1;target<s+1;target++){
                if(target-nums[i-1]>=0){
                    int a= dp[i-1][target-nums[i-1]];
                    if(a==1) 
                        dp[i][target]=1;
                    else
                        dp[i][target]=dp[i-1][target];
                }
                else dp[i][target]=dp[i-1][target];
            }
        }
        return dp[n][s]==0?false:true;

        // int ans= solve(nums, n, sum/2, dp);
        // return ans==0?false:true;
    }
}