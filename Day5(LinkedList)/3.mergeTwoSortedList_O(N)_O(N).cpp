#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<ListNode*, ListNode*> addNewNode(int val, ListNode* curr, ListNode* ans){
        
        ListNode* newNode= new ListNode(val);
        if(!ans) {
            ans=newNode;
            curr=ans;
        } else {
            curr->next=newNode;
            curr=curr->next;
        }
        return {ans, curr};
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=NULL, * curr=NULL;
        
        while(list1 && list2){
            if(list1->val < list2->val){
                auto it=addNewNode(list1->val, curr, ans);
                ans=it.first, curr=it.second;
                list1=list1->next;
            } else{
                auto it=addNewNode(list2->val, curr, ans);
                ans=it.first, curr=it.second;
                list2=list2->next;
            }
        }
        
        while(list1){
            auto it=addNewNode(list1->val, curr, ans);
            ans=it.first, curr=it.second;
            list1=list1->next;
        }
        while(list2){
            auto it=addNewNode(list2->val, curr, ans);
            ans=it.first, curr=it.second;
            list2=list2->next;
        }
        
        return ans;
    }
};