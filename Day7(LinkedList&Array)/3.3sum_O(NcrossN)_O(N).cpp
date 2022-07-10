#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=size(nums);        
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        
        for(int i=0;i<n-2;){
            int left=i+1, right=n-1;
			while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                
                if(sum>0){ //move right ptr;
                    int currR=nums[right];
                    while(right>0 && nums[right]==currR) right--;
                } else if(sum<0) { //move left ptr;
                    int currL=nums[left];
                    while(left<n && nums[left]==currL) left++;
                } else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    int currL=nums[left];
                    while(left<n && nums[left]==currL) left++;
                }
            }
            
            int currEle= nums[i];
            while(i<n&& nums[i]==currEle) i++;
        }
        
        return ans;
    }
};