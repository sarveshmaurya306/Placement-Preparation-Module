#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        // a[i]<a[i+1] //l-r == ind1
        // a[ind2] > a[ind1] // r-l
        //swap(a[ind1], a[ind2])
        //reverse(ind1+1,->last)
        int n= a.size();
        if(n==1) return;
        if(n==2) {
            swap(a[0], a[1]);
            return;
        }
        
        bool isDec=true;
        
        for(int i=0;i<n-1;i++){
            if(a[i]<a[i+1]){
                isDec=false;
                break;
            }
        }
        
        if(isDec){
            reverse(a.begin(), a.end());
            return;
        }
        
        int ind1=-1;
        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                ind1=i;
                break;
            }
        }
        int ind2=-1;
        for(int i=n-1;i>=0;i--){
            if(a[i]> a[ind1]){
                ind2=i;
                break;
            }
        }
        
        swap(a[ind1], a[ind2]);
        reverse(a.begin()+ind1+1, a.end());
    }
};