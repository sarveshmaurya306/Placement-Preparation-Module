#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* rev(ListNode* root, ListNode* pre){
        if(!root) return root;
        if(!root->next){
            root->next=pre;
            return root;
        }
        
        ListNode* next= root->next;
        root->next=pre;
        return rev(next, root);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=nullptr;
        return rev(head, pre);
    }
};