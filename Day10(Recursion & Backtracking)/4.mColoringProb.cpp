//!on coding ninjas

#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> & mat, int currNode, vector<int>& color, int currColor){
    for(int i=0;i<mat[currNode].size();i++){
        if(mat[currNode][i]==1 && color[i]==currColor) return false;
    }
    return true;
}

bool solve(vector<vector<int>>& mat, int m, int currNode, vector<int>& color){
    int n= mat.size();
    if(currNode==n) return true;
    
    for(int i=1;i<=m;i++){
        if(isSafe(mat, currNode, color, i)){
            color[currNode]=i;
            if(solve(mat, m, currNode+1, color)) return true;
            color[currNode]=0;
        }
    }
    
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {    
    vector<int> color(mat.size(), 0);
    if(solve(mat, m, 0, color)) return "YES";
    return "NO";
}