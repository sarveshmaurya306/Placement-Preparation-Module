#include<bits/stdc++.h>
using namespace std;
//!done on coding ninjas

int ans;
void solve(BinaryTreeNode<int> *node, int x){
    if(!node) return;
    if(node->data >= x) ans= min(node->data, ans);
    if(node->data==x) return;
    if(x<node->data){
        solve(node->left, x);
        return ;
    }
    solve(node->right, x);
}


int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    ans=INT_MAX;
    solve(node, x);
    return ans==INT_MAX?-1:ans;
}