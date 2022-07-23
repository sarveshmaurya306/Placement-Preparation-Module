#include<bits/stdc++.h>
using namespace std;


class Solution {
    
//     int solve(int[] nums, int i, int prevInd, int [][] dp){
//         if(i>=nums.length) return 0; 
//         if(dp[i][prevInd+1]!=-1) return dp[i][prevInd+1];
//         int maxi= 0;
//         if(prevInd ==-1 || nums[i] > nums[prevInd])
//             maxi= 1+solve(nums, i+1, i, dp);
//         return dp[i][prevInd+1]=Math.max(maxi, solve(nums, i+1, prevInd, dp));
//     }
    
    public int lengthOfLIS(int[] nums) {
        int n= nums.length+1;
        int [][] dp= new int[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) 
                dp[i][j]=0;
        
        for(int i= nums.length-1;i>=0;i--){
            for(int prevInd= i-1;prevInd>=-1;prevInd--){
                int len= 0+dp[i+1][prevInd+1];
                if(prevInd==-1 || nums[i]>nums[prevInd])
                    len= Math.max(len, 1+dp[i+1][i+1]);
                dp[i][prevInd+1]= len;
            }
        }
                                          
        return dp[0][0];
                                          
        // return solve(nums, 0, -1, dp);
    }
}