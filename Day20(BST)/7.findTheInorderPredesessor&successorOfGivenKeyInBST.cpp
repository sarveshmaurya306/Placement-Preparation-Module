#include<bits/stdc++.h>
using namespace std;

//!getting some error but code is correct it seems

int pre, succ;

void getPre(BinaryTreeNode<int>* root){
    if(!root) return ;
    pre= root->data;
    
    getPre(root->right);
} 
void getSuc(BinaryTreeNode<int>* root){
    if(!root) return ;
    succ=root->data;
    
    getPre(root->left);
} 
BinaryTreeNode<int>* solve(BinaryTreeNode<int>* root, int key){
    if(root->data==key) return root;
    
    if(key>root->data){
        pre= root->data;
        return solve(root->right, key);
    } else{
       succ= root->data; 
       return solve(root->left, key);
    } 
    return root;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key){
    pre=-1, succ=-1;
    
    auto it=solve(root, key);
    getSuc(it->right);
    getPre(it->left);
    return {pre, succ};
}


//SOLUTION CODE

pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int predecessor = -1;
    int successor = -1;

    // Reach to the key.
    while (root -> data != key)
    {
        if (key > root -> data)
        {
            predecessor = root -> data;
            root = root -> right;
        }
        else
        {
            successor = root -> data;
            root = root -> left;
        }
    }

    
    BinaryTreeNode<int>* rightSubtree = root -> right;

    while (rightSubtree != NULL)
    {
        successor = rightSubtree -> data;
        rightSubtree = rightSubtree -> left;
    }


    BinaryTreeNode<int>* leftSubtree = root -> left;

    while (leftSubtree != NULL)
    {
        predecessor = leftSubtree -> data;
        leftSubtree = leftSubtree -> right;
    }

    return {predecessor, successor};
}