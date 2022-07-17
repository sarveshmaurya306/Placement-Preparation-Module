class Solution {
public:
    Node* connect(Node* root) {
        //do level order traversal; and at last insert null 
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        
        while(q.size()>0){
            int size= q.size();
            Node* prev=NULL;
            for(int i=0;i<size;i++){
                auto top= q.front(); q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                
                if(prev) prev->next= top, prev=prev->next;
                else prev= top;
            }
            prev->next= nullptr;
        }
        return root;
    }
};