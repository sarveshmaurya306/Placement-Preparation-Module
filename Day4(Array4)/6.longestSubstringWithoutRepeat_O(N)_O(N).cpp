#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
    
        int i=0, j=0, n=s.size();
        int maxi=0;
        
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]>1){ //delete character from start;
                while(mp[s[j]]>1) {
                    mp[s[i]]--;
                    i++;
                }
            }
            maxi=max(j-i+1, maxi);
            j++;
        }
        return maxi;
    }
};