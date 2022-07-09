class Solution {
public:
    string str="";
    void solve(ListNode* head){
        if(head==NULL) return;
        str.push_back((char)(head->val+(int)'0'));
        solve(head->next);
    }
    bool isPalindrome(ListNode* head) {
        solve(head);
        cout<<str<<endl;
        string a= str;
        reverse(str.begin(), str.end());
        return a==str;
    }
};