#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //index->nums[i]-1
        int n= nums.size();
        
        //iterate and mark negative as soon as we saw elem is also neg 
        //then return this as this is seen earlier;
        
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0) return abs(nums[i]);
            nums[abs(nums[i])-1]*=-1;
        }
        
        return -1;
    }
};