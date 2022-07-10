class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp; //old->new;
        mp[NULL]=NULL;
        
        auto it= head;
        while(it) {
            mp[it]=new Node(it->val);
            it=it->next;
        }
        
        Node* newHead=NULL;
        Node* curr=head;
        
        it=head;
        while(it!=NULL){
            auto next= it->next;
            auto random= it->random;
            
            if(!newHead){
                newHead=mp[it];
                newHead->next=mp[next];
                newHead->random= mp[random];
                curr=newHead;
            } else{
                curr=mp[it];
                curr->next=mp[next];
                curr->random= mp[random];
                curr=curr->next;
            }
            it=next;
        }
        
        return newHead;
    }
};