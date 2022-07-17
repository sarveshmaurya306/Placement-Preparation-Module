#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans;
    
    int solve(TreeNode* root){
        if(!root) return 0;
        
        int leftSum= max(0, solve(root->left));
        int rightSum= max(0, solve(root->right));
        
        ans= max(ans, leftSum+rightSum+root->val);
        return max(leftSum, rightSum)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        solve(root);
        return ans;
    }
};