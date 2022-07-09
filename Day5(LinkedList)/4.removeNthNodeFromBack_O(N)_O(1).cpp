#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * fast, *slow; 
        fast=slow=head;
        
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL) return head->next;
        
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        //cout<<slow->val<<" "<<slow->next->val<<endl;
        slow->next=slow->next->next;
        return head;
    }
};