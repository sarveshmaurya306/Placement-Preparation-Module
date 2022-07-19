class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string ans="";
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()){
            auto top= q.front(); q.pop();
            if(top==nullptr) {
                ans+="NULL";
                ans+=" ";
                continue;
            }
            ans+=to_string(top->val);
            ans+=" ";
            
            auto left= top->left;
            auto right= top->right;
            q.push(left);
            q.push(right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        
        string temp;
        stringstream ss(data);
        ss>>temp;
        
        TreeNode* root=new TreeNode(stoi(temp));
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()){
            auto top= q.front(); q.pop();
            if(top==NULL) continue;
            ss>>temp;
            top->left= temp=="NULL"?NULL: new TreeNode(stoi(temp));
            ss>>temp;
            
            top->right= temp=="NULL"?NULL: new TreeNode(stoi(temp));
            q.push(top->left);
            q.push(top->right);
        }
        return root;
    }
};
