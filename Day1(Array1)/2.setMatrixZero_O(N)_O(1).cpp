#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m=arr.size(), n= arr[0].size();
       
        bool changeFirstCol=false;
        //marking step
        for(int i=0;i<m;i++){
            if(arr[i][0]==0) changeFirstCol=true;
            for(int j=1;j<n;j++){
                if(arr[i][j]==0) arr[i][0]=arr[0][j]=0;
            }
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(arr[i][0]==0 || arr[0][j]==0) arr[i][j]=0;
            }
            if(changeFirstCol) arr[i][0]=0;
        }
        
    }
};