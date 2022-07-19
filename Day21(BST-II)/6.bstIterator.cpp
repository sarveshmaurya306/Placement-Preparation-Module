#include<bits/stdc++.h>
using namespace std;

//first push all the left in the stack 
//if remove and element then push all the left of the curr->right;
//if stack is empty then return false otherwise true;

class BSTIterator {
public:
    stack<TreeNode* > st;
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    void pushAllLeft(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        auto top= st.top(); st.pop();
        pushAllLeft(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};