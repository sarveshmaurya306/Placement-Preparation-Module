#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void deleteNode(ListNode* node) {
        int temp= node->next->val;
        node->next->val=node->val;
        
        node->val=temp;
        node->next=node->next->next;
    }
};