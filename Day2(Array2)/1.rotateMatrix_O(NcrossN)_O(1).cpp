#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void swapCol(vector<vector<int>>& mat, int start, int end){
        int n= mat.size();

        for(int i=0;i<n;i++){ //going to all the rows
            swap(mat[i][start], mat[i][end]);
        }
    }
    
    void rotate(vector<vector<int>>& mat) {
        //take transpose and then swap start and last col
        
        //step1-> taking transpose of a matrix;
        int n= mat.size();
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                swap(mat[i][j], mat[j][i]);
        
        //step2-> swap start and end col
        int start= 0, end= n-1;
        while(start<end){
            swapCol(mat, start, end);
            start++, end--;
        }
    }
}; 