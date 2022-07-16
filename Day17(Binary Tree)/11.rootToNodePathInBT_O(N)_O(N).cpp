#include<bits/stdc++.h>
using namespace std;
// on interview bit

bool find(TreeNode* root, int target, stack<int>& s){
    if(!root) return false;
    if(root->val==target){
        s.push(target);
        return true;
    }
    
    if (find(root->left, target, s) || find(root->right, target, s)){
        s.push(root->val);
        return true;
    }
    return false;
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    stack<int> s;
    find(A, B, s);
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
