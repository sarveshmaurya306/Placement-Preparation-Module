#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& cand, int target, vector<int>& temp, int ind){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=ind;i<size(cand);i++){
            if(i>ind && cand[i]==cand[i-1]) continue;
            if(cand[i]>target) break;
            temp.push_back(cand[i]);
            solve(cand, target-cand[i], temp, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(), can.end());
        vector<int> temp;
        solve(can, target, temp, 0);
        
        return ans;
    }
};