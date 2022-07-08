#include<bits/stdc++.h>
using namespace std;

//modification of boyers moore algo
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=-1, ele2=-1;
        int cnt1=0, cnt2=0;
        
        for(int i: nums){
            if(i==ele1) cnt1++;
            else if(i==ele2) cnt2++;
            else if(cnt1==0){
                ele1=i;
                cnt1=1;
            } else if(cnt2==0){
                ele2=i;
                cnt2=1;
            } else cnt1--, cnt2--;
        }
        
        vector<int> ans;
        int ele1Cnt=0, ele2Cnt=0;
        
        for(int i: nums){
            if(i==ele1) ele1Cnt++;
            else if(i==ele2) ele2Cnt++;
        }
        
        int n = nums.size();
        if(ele1Cnt>n/3) ans.push_back(ele1);
        if(ele2Cnt>n/3) ans.push_back(ele2);
        
        return ans;
    }
};