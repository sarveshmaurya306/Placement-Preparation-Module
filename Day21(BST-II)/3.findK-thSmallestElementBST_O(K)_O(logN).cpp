#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int last;
    int ans;
    
    void inorder(TreeNode* root){
        if(!root) return ;
        
        inorder(root->left);
        last--;
        if(last==0){
            ans=root->val;
            return;
        }
        inorder(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        //traverse inorder then reduce k;
        last=k;
        inorder(root);
        return ans;
    }
};