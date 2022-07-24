//! on gfg

class Solution{
public:
    vector<int> dp;
    bool solve(string &a, int ind, unordered_map<string, bool> &mp){
        if(ind>=a.size()) return true;
        if(dp[ind]!=-1) return dp[ind];
        
        string temp="";
        
        for(int i=ind;i<a.size();i++){
            temp.push_back(a[i]);
            if(mp.find(temp)!=mp.end()){ //break and try on each index if present then then try for the next match otherwise try next
                bool take= solve(a, i+1, mp);
                if(take) return dp[ind]=true;
            }
        }
        
        return dp[ind]=false;
    }

    int wordBreak(string a, vector<string> &b) {
        unordered_map<string, bool> mp;
        dp.resize(a.size()+1, -1);
        
        for(string &s: b) mp[s]=true;
        
        return solve(a, 0, mp);
    }
};