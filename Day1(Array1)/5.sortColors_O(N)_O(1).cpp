#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // divide in 3 parts;
        //DNF algo
        int i, j, k, n=nums.size();
        i=j=0, k=n-1;
        
        while(j<=k){
            if(nums[j]==0){
                swap(nums[j++], nums[i++]);
            } else if(nums[j]==1){
                j++;
            } else if(nums[j]==2){
                swap(nums[j], nums[k--]);
            }
        }
    }
};