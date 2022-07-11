#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    bool isPal(string& s){
        string x=s;
        reverse(x.begin(), x.end());
        if(x==s) return true;
        return false;
    }
    
    void solve(string & s, vector<string> &temp, int ind){
        if(ind>=s.size()){
            ans.push_back(temp);
            return;
        }
        
        string x="";
        for(int i=ind;i<s.size();i++){
            x.push_back(s[i]);
            if(isPal(x)){
                temp.push_back(x);
                solve(s, temp, i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s, temp, 0);
        return ans;
    }
};