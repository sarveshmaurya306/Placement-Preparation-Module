class Solution {
public:
    int ind=0;
    Solution(){ind=0;}
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        return solve(pre, INT_MAX);
    }
    
    TreeNode* solve(vector<int>& pre, int ub){
        if(ind==pre.size() || pre[ind] > ub) return NULL;
        
        TreeNode* root= new TreeNode(pre[ind++]);
        TreeNode* left= solve(pre, root->val);
        TreeNode* right=solve(pre, ub);
        root->left= left, root->right=right;
        
        return root;
    }
};