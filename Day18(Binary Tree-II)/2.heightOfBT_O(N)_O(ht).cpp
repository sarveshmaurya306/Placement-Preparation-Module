class Solution {
public:
    int solve(TreeNode* root, int level){
        if(!root) return level;
        return max(solve(root->left, level+1), solve(root->right, level+1));
    }
    
    int maxDepth(TreeNode* root) {
        return solve(root, 0);
    }
};