class Solution {
public:
    int getSize(ListNode* head){
        int cnt=0;
        while(head!=nullptr) {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        //similar like remove nth element from last(day5 q4)
        int size=getSize(head);
        k=k%size;
        if(k==0) return head;
        
        ListNode * fast, *slow; 
        fast=slow=head;
        
        for(int i=0;i<k;i++){
            fast=fast->next;
        }
        if(fast==NULL) return head;
        
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* next= slow->next;
        slow->next=nullptr;
        
        //we will retrun next;
        ListNode* nextLast=next;
        while(nextLast->next!=nullptr){
            nextLast=nextLast->next;
        }
        
        nextLast->next=head;
        return next;
    }
};