class Solution {
public:
    pair<bool,int> isBal(TreeNode* root){
        if(!root) return {true, 0};
        auto left= isBal(root->left);
        auto right= isBal(root->right);
        
        if(left.first && right.first)
            return {abs(left.second-right.second)<=1, max(left.second, right.second)+1};
        return {false, INT_MAX};
    }
    
    bool isBalanced(TreeNode* root) {
        auto it=isBal(root);
        return it.first;
    }
};