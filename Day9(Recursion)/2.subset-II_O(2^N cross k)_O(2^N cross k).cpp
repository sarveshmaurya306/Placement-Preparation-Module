#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums, vector<int> &temp, int ind){
        //pick only first occurence
        int n=nums.size();
        ans.push_back(temp);
        for(int i=ind;i<n;i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums, temp, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums, temp, 0);

        return ans;
    }
};

//brute force

//class Solution {
//public:
//    set<vector<int>> tans;
    
//    void solve(vector<int>& nums, vector<int> &temp, int ind){
//        int n= nums.size();
//        if(ind>=n) {
//            tans.insert(temp);
//            return;
//        }
        
//        temp.push_back(nums[ind]);
//        solve(nums, temp, ind+1);
//        temp.pop_back();
        
//        solve(nums, temp, ind+1);
//    }
    
//    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        vector<int> temp;
//        solve(nums, temp, 0);
        
//        vector<vector<int>> ans;
//        for(auto it: tans) ans.push_back(it);
        
//        return ans;
//    }
//};