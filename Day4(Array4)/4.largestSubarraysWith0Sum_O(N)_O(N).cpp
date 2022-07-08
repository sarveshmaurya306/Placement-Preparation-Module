#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&a, int n){
        //see the first index and last index of repeating sum
        unordered_map<int, int> mp;
        int maxi=0;
        int sum=0;
        mp[0]=-1; //seen on before start
        
        for(int i=0;i<n;i++){
            sum+= a[i];
            if(mp.find(sum)!=mp.end()){
                maxi=max(maxi, i-mp[sum]);
            } else{
                mp[sum]=i;
            }
        }
        return maxi;
    }
};
