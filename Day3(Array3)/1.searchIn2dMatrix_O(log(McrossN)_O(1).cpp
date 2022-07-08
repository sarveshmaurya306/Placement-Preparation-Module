#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find(vector<vector<int>>& mat, int tar, int i, int j){
        if(i>=mat.size() || j<0) return false;
        
        if(mat[i][j] < tar) return find(mat, tar, i+1, j);
        else if(mat[i][j]>tar) return find(mat, tar, i, j-1);
        return true;
    }
    
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        return find(mat, tar, 0, mat[0].size()-1);
    }
};