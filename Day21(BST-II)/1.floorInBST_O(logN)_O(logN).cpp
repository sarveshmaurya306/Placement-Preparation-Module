#include<bits/stdc++.h>
using namespace std;
//!done on coding ninjas


int floorInBST(TreeNode<int> * root, int x){
    if(!root) return -1;
    if(x<root->val){
        return floorInBST(root->left, x);
    } else if(x>root->val){
        return max(root->val, floorInBST(root->right, x));
    } 
    return x;
}