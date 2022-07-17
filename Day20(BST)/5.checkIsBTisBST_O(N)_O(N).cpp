#define ll long long

class Solution {
public:
    bool solve(TreeNode* root, ll lo, ll hi){
        if(!root) return true;
        if(root->val>lo && root->val<hi)
            return solve(root->left, lo, root->val) && solve(root->right, root->val, hi);
        
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};