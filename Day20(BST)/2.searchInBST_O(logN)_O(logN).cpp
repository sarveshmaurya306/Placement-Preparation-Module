class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        if(root->val==val) return root;
        
        TreeNode* l= searchBST(root->left, val);
        if(l) return l;
        return searchBST(root->right, val);
    }
};