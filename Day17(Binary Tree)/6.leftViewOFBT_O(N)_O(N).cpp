//!on code studio (coding ninjas)

#include<bits/stdc++.h>
using namespace std;

vector<int> getLeftView(TreeNode<int> *root){
    if(!root) return {};
    queue<TreeNode<int>*> q;
    q.push(root);
    vector<int> ans;
    
    while(!q.empty()){
        int size= q.size();
        ans.push_back(q.front()->data);
        
        for(int i=0;i<size;i++){
            auto top= q.front(); q.pop();
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
    }
    return ans;
}