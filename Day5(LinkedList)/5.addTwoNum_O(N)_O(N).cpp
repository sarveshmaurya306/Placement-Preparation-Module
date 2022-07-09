#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<ListNode*, ListNode*> addNewNode(int val, ListNode* ans, ListNode* curr){
        if(ans==nullptr){
            ans=new ListNode(val);
            curr=ans;
        } else{
            curr->next= new ListNode(val);
            curr=curr->next;
        }
        return {ans, curr};
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ans=NULL;
        ListNode* last=NULL;
        
        while(l1 && l2){
            int sum= l1->val + l2->val+carry;
            int lastDig=sum%10;
            carry= sum/10;
            auto it= addNewNode(lastDig, ans, last);
            ans=it.first, last=it.second;
            
            l1=l1->next, l2=l2->next;
        }
        while(l1){
            int sum= l1->val +carry;
            int lastDig=sum%10;
            carry= sum/10;
            
            auto it= addNewNode(lastDig, ans, last);
            ans=it.first, last=it.second;
            
            l1=l1->next;
        }
        while(l2){
            int sum= l2->val +carry;
            int lastDig=sum%10;
            carry= sum/10;
            
            auto it= addNewNode(lastDig, ans, last);
            ans=it.first, last=it.second;
            
            l2=l2->next;
        }
        if(carry){
            auto it= addNewNode(carry, ans, last);
            ans=it.first, last=it.second;
        }
        return ans;
    }
};