#include<bits/stdc++.h>
using namespace std;

//!on gfg

class Solution {
  public:
    Node* solve(Node* root){
        if(!root) return nullptr;
        
        auto left= solve(root->left);
        auto right= solve(root->right);
        
        root->left= right;
        root->right= left;
        return root;
    }
  
    void mirror(Node* node) {
        //just swap its left and right node;
        solve(node);
    }
};