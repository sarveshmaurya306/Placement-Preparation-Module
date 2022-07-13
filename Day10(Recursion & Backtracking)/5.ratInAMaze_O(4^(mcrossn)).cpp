#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> ans;
    vector<pair<int,int>> dir={{0,-1},{-1,0},{1,0},{0,1}};
    
    void solve(vector<vector<int>> &m, int n, int i, int j, string &temp){
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        
        m[i][j]=0;
        for(int x=0;x<4;x++){
            int newX=i+dir[x].first;
            int newY= j+dir[x].second;
            char ch;
            
            if(dir[x].first==0 && dir[x].second==-1) ch='L';
            else if(dir[x].first==-1 && dir[x].second==0) ch='U';
            else if(dir[x].first==1 && dir[x].second==0) ch='D';
            else if(dir[x].first==0 && dir[x].second==1) ch='R';
            
            if(newX>=0 && newX<n && newY>=0 && newY<n && m[newX][newY]!=0){
                temp.push_back(ch);
                solve(m, n, newX, newY, temp);
                temp.pop_back();
            }
        }
        m[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0 || m[n-1][n-1]==0) return {};
        string temp="";
        solve(m, n, 0, 0, temp);
        return ans;
    }
};
