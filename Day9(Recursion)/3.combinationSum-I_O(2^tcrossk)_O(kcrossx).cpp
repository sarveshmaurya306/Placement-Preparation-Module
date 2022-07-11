#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& cand, int target, vector<int>& temp, int ind){
        
        if(ind>=size(cand)){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(target-cand[ind]>=0){
            temp.push_back(cand[ind]);
            solve(cand, target-cand[ind], temp, ind);
            temp.pop_back();
            
            solve(cand, target, temp, ind+1);
        } else{
            solve(cand, target, temp, ind+1);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, target, temp, 0);
        
        return ans;
    }
};