#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, bool> mp;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        
        bool l=findTarget(root->left, k);
        
        if(l) return l;
        if(mp.find(k-root->val)!=mp.end()) return true;
        mp[root->val]=true;
        
        return findTarget(root->right, k);
    }
};