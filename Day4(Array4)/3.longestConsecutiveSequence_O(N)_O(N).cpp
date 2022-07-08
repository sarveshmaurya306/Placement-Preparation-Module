#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(int i: nums) mp[i]=true;
        
        int maxi=0;
        for(int i: nums){
            mp[i]=true;
            
            if(mp.find(i-1)==mp.end()){
                int cnt=0;
                int num=i;
                while(true){
                    if(mp.find(num)==mp.end()) break;
                    cnt++;
                    num++;
                }
                maxi=max(maxi, cnt);
            }
        }
        return maxi;
    }
};