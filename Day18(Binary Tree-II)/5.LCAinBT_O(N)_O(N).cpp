class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q){ //if any found
            return root;
        }
        auto left= lowestCommonAncestor(root->left, p, q);
        auto right= lowestCommonAncestor(root->right, p, q);
        
        if(left && right) return root; //if both found the this root is ans;
        if(left) return left; 
        if(right) return right;
        return nullptr;
    }
};