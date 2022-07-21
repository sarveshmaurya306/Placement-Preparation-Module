#include<bits/stdc++.h>
using namespace std;


vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int, int> freq;
    int cnt=0;
    
    vector<int> ans;
    
    int i, j,n=A.size(); i=j=0;
    while(j<n){
        freq[A[j]]++;
        if(freq[A[j]]==1)
            cnt++;
        
        if(j-i+1==B){
            ans.push_back(cnt);
            int key = A[i];
            freq[key]--;
            if(freq[key]==0) cnt--;
            
            i++;
        }
        j++;
    }
    return ans;
}
