#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(TreeNode* l, TreeNode* r){
        if(!l && r) return false;
        if(!r && l) return false;
        if(!l && !r) return true;
        //l && r
        if(l->val==r->val)
            return solve(l->left, r->right) && solve(l->right, r->left);
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};