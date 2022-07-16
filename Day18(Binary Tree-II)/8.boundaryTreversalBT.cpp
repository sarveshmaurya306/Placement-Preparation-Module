class Solution {
public:
    void leftTraversal(TreeNode* root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right) return;

        ans.push_back(root->val);

        if(root->left) leftTraversal(root->left, ans);
        else leftTraversal(root->right, ans);
    }
    void leefTraversal(TreeNode* root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right) {
            ans.push_back(root->val);
            return;
        }
        leefTraversal(root->left, ans);
        leefTraversal(root->right, ans);
    }
    void rightTraversal(TreeNode* root, vector<int> &ans){
        if(!root) return;
        if(!root->left && !root->right) return;
        
        if(root->right) leftTraversal(root->right, ans);
        else leftTraversal(root->left, ans);
        
        ans.push_back(root->val);        
    }

    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        //left exclu xding leaf;
        //only leaf by inorder traversal
        //right excluding leaf and then taking reverse;
        vector<int> ans;
        if(!root) return ans;
        if(!root->left && !root->right) ans.push_back(root->val);

        ans.push_back(root->val);
        leftTraversal(root->left, ans);
        leefTraversal(root, ans);
        rightTraversal(root->right, ans);

        return ans;
    }
};