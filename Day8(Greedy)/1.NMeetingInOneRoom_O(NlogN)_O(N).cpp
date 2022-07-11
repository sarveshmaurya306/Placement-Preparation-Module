#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool static comp(pair<int,int>& a, pair<int,int>& b){
        if(a.second!=b.second) return a.second<b.second;
        return a.first<b.first;
    }
    
    int maxMeetings(int start[], int end[], int n){
        vector<pair<int,int>> vc;
        for(int i=0;i<n;i++)
            vc.push_back({start[i], end[i]});
        
        sort(vc.begin(), vc.end(), comp);
        
        int cnt=1;
        int lastEnd= vc[0].second;
        
        for(int i=1;i<n;i++){
            if(vc[i].first > lastEnd){
                cnt++;
                lastEnd= vc[i].second;
            }
        }
        return cnt;
    }
};