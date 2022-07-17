class Solution {
public:
    int ind;
    Solution(){
        ind=0;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int, int> mp;
        for(int i=0;i<in.size();i++)
            mp[in[i]]=i;
        return solve(pre, mp, in, 0, pre.size()-1);
    }
    
    TreeNode* solve(vector<int> & pre, unordered_map<int,int> &mp, vector<int> &in, int start, int end){        
        if(start<0 || end>=pre.size() || start>end || ind>=pre.size()) return NULL;
        if(start==end) return new TreeNode(pre[ind++]);
        
        int currInd= mp[pre[ind]];
        
        TreeNode* node= new TreeNode(pre[ind++]);
        TreeNode* l=solve(pre, mp, in, start, currInd-1);
        TreeNode* r=solve(pre, mp, in, currInd+1, end);
        
        node->left=l, node->right=r;
        return node;
    }
    
    
};
