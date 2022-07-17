class Solution {
public:
    TreeNode* solve(vector<int> & nums, int lo, int hi){
        if(lo>hi) return nullptr;
        if(lo==hi) return new TreeNode(nums[lo]);
        
        int mid= (lo+hi)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left= solve(nums, lo, mid-1);
        root->right=solve(nums, mid+1, hi);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};