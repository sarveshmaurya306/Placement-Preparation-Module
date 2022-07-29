class Solution {
public:
    string match(string a, string b){
        string ans="";
        for(int i=0;i<a.size() && i<b.size(); i++){
            if(a[i]==b[i]) ans.push_back(a[i]);
            else break;
        }
        return ans;
    }
    
    string longestCommonPrefix(vector<string>& str) {
        string pref=str[0];
        
        for(int i=1;i<str.size();i++)
            pref=match(pref, str[i]);
        return pref;
    }
};