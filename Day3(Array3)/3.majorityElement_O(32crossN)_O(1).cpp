#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0, n= nums.size();
        
        for(int i=31;i>=0;i--){
            int cntOnes=0;
            for(int num: nums){
                if(num & (1<<i)) cntOnes++;
            }
            
            if(cntOnes>n/2){
                ans= ans|(1<<i);
            } 
        }
        //O(32*N)
        //O(1)
        return ans;
    }
};