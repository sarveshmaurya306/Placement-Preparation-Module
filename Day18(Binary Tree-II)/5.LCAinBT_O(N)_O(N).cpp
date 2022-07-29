/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   TreeNode* ans;    
   pair<bool, bool> solve(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(!root) return {false, false}; 
       
       auto leftAns=solve(root->left, p, q);
       auto rightAns=solve(root->right, p, q);
       
       if(root==p) leftAns.first= true, rightAns.first=true;
       if(root==q) leftAns.second= true, rightAns.second=true;
       
       if((leftAns.first || rightAns.first) && (leftAns.second||rightAns.second)){
           if(!ans) ans= root;
       }
       
       return {(leftAns.first || rightAns.first), (leftAns.second||rightAns.second)};
   }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //start from child and keep track of p, q found in child or not;
        //case 1: root==p || root==q if here both are true then this is LCA
        solve(root, p, q);
        return ans;
    }
};