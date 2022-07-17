#include<bits/stdc++.h>
using namespace std;
void leftTraversal(TreeNode<int>* root, vector<int>& ans){
    if(!root) return;
    if(!root->left && !root->right) return;

    ans.push_back(root->data);

    if(root->left) leftTraversal(root->left, ans);
    else leftTraversal(root->right, ans);
}
void leefTraversal(TreeNode<int>* root, vector<int>& ans){
    if(!root) return;
    if(!root->left && !root->right) {
        ans.push_back(root->data);
        return;
    }
    leefTraversal(root->left, ans);
    leefTraversal(root->right, ans);
}
void rightTraversal(TreeNode<int>* root, vector<int> &ans){
    if(!root) return;
    if(!root->left && !root->right) return;

    if(root->right) leftTraversal(root->right, ans);
    else leftTraversal(root->left, ans);

    ans.push_back(root->data);        
}

vector<int> traverseBoundary(TreeNode<int>* root){
    
    vector<int> ans;
    if(root==NULL) return ans;
    
    ans.push_back(root->data);
    
    leftTraversal(root->left, ans);
    
    leefTraversal(root->left, ans);
    leefTraversal(root->right, ans);
    
    rightTraversal(root->right, ans);
    
    return ans;
}