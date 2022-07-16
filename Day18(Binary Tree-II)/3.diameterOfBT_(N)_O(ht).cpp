class Solution {
public:
    int ans;
    int solve(TreeNode* root){
        if(!root) return 0;
        
        int left= solve(root->left);
        int right= solve(root->right);
        ans=max(ans, left+right);
        
        return max(left, right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        solve(root);
        return ans;
    }
};