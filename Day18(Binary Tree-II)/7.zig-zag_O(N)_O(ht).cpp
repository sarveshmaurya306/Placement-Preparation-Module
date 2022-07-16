class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> ans;
        bool flag=false; //no rev;
        
        while(!q.empty()){
            vector<int> temp;
            int size= q.size();
            for(int i=0;i<size;i++){
                auto top= q.front();
                temp.push_back(top->val);
                
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                q.pop();
            }
            if(flag)
                reverse(temp.begin(), temp.end());
            flag=!flag;
            ans.push_back(temp);
        }
        return ans;
    }
};