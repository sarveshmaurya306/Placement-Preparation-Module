//on coding ninjas

int solve(BinaryTreeNode < int > * root){
    if(!root) return 0;
    int child=0;
    if(root->left) child+= root->left->data;
    if(root->right) child+= root->right->data;
    
    if(child>=root->data) root->data= child;
    else{
        if(root->left) root->left->data= root->data;
        else if(root->right) root->right->data =root->data;
    }
    int left= solve(root->left);
    int right= solve(root->right);
    
    root->data= max(root->data, left+right);
    return root->data;
}

void changeTree(BinaryTreeNode < int > * root) {
    solve(root);
}  