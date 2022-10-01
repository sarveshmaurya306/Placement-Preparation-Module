#include<bits/stdc++.h>
long check(vector<vector<int>>& mat, long mid){
    long cnt=0;
    for(int i=0;i<mat.size();i++){
        cnt+= upper_bound(mat[i].begin(), mat[i].end(), mid)- mat[i].begin();
    }
    return cnt;
}

int getMedian(vector<vector<int>> &matrix){
    long lo=1, hi=1e9;
    int half= (matrix.size()* matrix[0].size()) / 2;
    while(lo<=hi){
        long mid= lo+(hi-lo)/2;
        long cnt= check(matrix, mid);
        if(cnt> half) hi= mid-1;
        else lo=mid+1;
    }
    return lo;
}

