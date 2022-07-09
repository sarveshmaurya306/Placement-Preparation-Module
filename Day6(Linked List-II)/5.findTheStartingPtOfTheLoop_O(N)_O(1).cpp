class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head, *fast=head; 
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) {//has cycle
                slow=head; //additional step than detect cycle
                while(true){
                    if(slow==fast) return slow;
                    slow=slow->next;
                    fast=fast->next;
                }
            }
        }
        
        return nullptr;
    }
};