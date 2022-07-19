#include<bits/stdc++.h>
using namespace std;



//!APROACH 1(BRUTE FORCE) //O(N*N) solution
//!self solution without knowing the actual solution
//check each and every node if any node return INT_MIN -> from that node no bst gets formed
//so try left, and right

class Solution {
public:
    int ans=INT_MIN;
    int solve(TreeNode* root, int lb, int ub){
        if(!root) return 0;
        
        if(lb >= root->val || root->val >= ub) return INT_MIN;
        
        int leftSum= solve(root->left, lb, root->val);
        if(leftSum==INT_MIN) return INT_MIN;
        
        int rightSum= solve(root->right, root->val, ub);
        if(rightSum==INT_MIN) return INT_MIN;

        int sum= leftSum+rightSum+root->val;
        ans= max(ans, sum);
        return sum;
    }
    
    void helper(TreeNode* root){
        if(!root) return ;
        
        if(solve(root, INT_MIN, INT_MAX)!=INT_MIN) return;
        
        helper(root->left);
        helper(root->right);
    }
    
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans<0?0:ans;
    } 
};


//!APPROACH 2 O(N)
class Solution {
public:
    int ans=INT_MIN;
    
    vector<int> solve(TreeNode* root){ // min, max, sum
        if(!root) return {INT_MAX, INT_MIN, 0};
        
        auto left=solve(root->left);
        auto right=solve(root->right);
    
        //check tree is bst or not 
        //if not then
        if(left.empty() || right.empty() || root->val<=left[1] || root->val>=right[0]) return {};
        
        //if yes then;
        int sum=left[2]+right[2]+root->val;
        ans=max(ans, sum);
        return {min(root->val, left[0]), max(root->val, right[1]), sum};
        
    }
    
    int maxSumBST(TreeNode* root) {
        solve(root);
        return max(ans, 0);
    }
};