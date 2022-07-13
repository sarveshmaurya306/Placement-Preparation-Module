#include<bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    vector<vector<string>> ans;
    
    bool isSafe(vector<string> &temp, int i, int j){
        int m= temp.size();
        int x=i, y=j;
        for(int ii=0;ii<x;ii++) if(temp[ii][j]=='Q') return false;
        
        while(x>=0 && y>=0){
            if(temp[x][y]=='Q') return false;
            x--, y--;
        }
        x=i, y=j;
        while(x>=0 && y<m){
            if(temp[x][y]=='Q') return false;
            x--, y++;
        }
        return true;
    }
    
    void solve(vector<string> &temp, int i){
        int m= temp.size();
        if(i>m) return ;
        if(i==m){
            ans.pb(temp);
            return;
        }
        
        for(int j=0;j<m;j++){
            if(!isSafe(temp, i, j)) continue;
            temp[i][j]='Q';
            solve(temp, i+1);
            temp[i][j]='.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s= "";
        for(int i=0;i<n;i++) s.pb('.');
        
        vector<string> temp;
        for(int i=0;i<n;i++) temp.pb(s);
        solve(temp, 0);
        return ans;
    }
};