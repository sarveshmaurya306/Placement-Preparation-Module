#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=size(nums);
        int i=0, j=0;
        while(j<n){
            if(nums[i]==nums[j]) j++;
            else{
                nums[i+1]=nums[j];
                i++, j++;
            }
        }
        return i+1;
    }
};