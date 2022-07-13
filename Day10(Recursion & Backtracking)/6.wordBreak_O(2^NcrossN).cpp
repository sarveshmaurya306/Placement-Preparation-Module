//! done on coding ninja

//!trie ke use krke bhi kr skte

#include<bits/stdc++.h>
using namespace std;

void solve(string &s, string &temp, string& temp2, int ind, unordered_map<string, bool> &dict, vector<string> &ans){
    if(ind>=s.size()){
        if(dict.find(temp)!=dict.end()){
            temp2+= temp;
            ans.push_back(temp2);
        }
        return;
    }
    
    if(dict.find(temp)!=dict.end()){ //found this 
        // 2choice choose this or skip this
        string prev= temp2;
        string tempprev= temp;
        
        temp2+= temp+" ";
        temp="";
        temp.push_back(s[ind]);
        solve(s, temp, temp2, ind+1, dict, ans);
        temp.pop_back();
        
        temp2=prev;
        temp=tempprev;
        temp.push_back(s[ind]);
        solve(s, temp, temp2, ind+1, dict, ans);
        temp.pop_back();
        
        return ;
    }
    
    temp.push_back(s[ind]);
    solve(s, temp, temp2, ind+1, dict, ans);
    temp.pop_back();
}


vector<string> wordBreak(string &s, vector<string> &dictionary){
    unordered_map<string, bool> dict;
    vector<string> ans;
    
    for(string &s: dictionary) dict[s]=true;
    string temp="";
    string temp2="";
    solve(s, temp,temp2, 0, dict, ans);
    dict.clear();
    return ans;
}