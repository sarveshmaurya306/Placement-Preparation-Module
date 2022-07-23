#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini=1, maxi=1;
        int overallMax= nums[0];
        
        for(int i=0;i<nums.size();i++){
            int num= nums[i];
            if(num==0){
                mini=maxi=1;
                overallMax= max(overallMax, 0);
                continue;
            }
            int temp= mini;
            mini= min({num, num*mini, num*maxi});
            maxi= max({num, num*temp, num*maxi});
            overallMax= max(overallMax, maxi);
        }
        
        return overallMax;
    }
};