#include<bits/stdc++.h>
using namespace std;

//!done on gfg
//TODO just reverse of kth smallest element

class Solution{
    public:
    int last;
    int ans;
    
    void inorder(Node* root){
        if(!root) return ;
        
        inorder(root->right);
        last--;
        if(last==0){
            ans=root->data;
            return;
        }
        inorder(root->left);
    }
    
    int kthLargest(Node *root, int K){
        last=K;
        inorder(root);
        return ans;
    }
};