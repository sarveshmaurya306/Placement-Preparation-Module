#include<bits/stdc++.h>
using namespace std;

/**
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 */

class Solution {
public:
    int leftest, rightest; //to keep track of leftmost and rightmost ind value coz wanna use unordered_map
    void solve(TreeNode* root, unordered_map<int, map< int, vector<int> >> &mp, int ind, int level){
        if(!root) return;
        
        leftest=min(leftest, ind);
        rightest=max(rightest, ind);
        
        solve(root->left, mp, ind-1, level+1);
        solve(root->right, mp, ind+1, level+1);
        
        if(mp.find(ind)==mp.end()){ //not found
            map<int, vector<int>> t;
            t[level]={};
            mp[ind]= t;
        }
        mp[ind][level].push_back(root->val);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, map< int, vector<int> >> mp; // ind-> level-> ele;
        leftest=INT_MAX;
        rightest=INT_MIN;
        
        solve(root, mp, 0, 0);
        
        vector<vector<int>> ans;
        for(int i=leftest;i<=rightest;i++){ //index traversing
            vector<int> tempAns;
            for(auto level: mp[i]){ //level traversing
                sort(level.second.begin(), level.second.end()); //as req sorted ele
                for(int t: level.second) tempAns.push_back(t);
            }
            ans.push_back(tempAns);
        }
        return ans;
    }
};