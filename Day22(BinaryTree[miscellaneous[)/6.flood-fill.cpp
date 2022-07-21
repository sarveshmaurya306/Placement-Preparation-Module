#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<bool>> &vis){
        
        int m= image.size(), n= image[0].size();
        
        if(sr<0 || sc<0 || sr>=m || sc>=n || vis[sr][sc]) return;
        vis[sr][sc]=true;
        
        if(sc+1<n && image[sr][sc]==image[sr][sc+1])
            solve(image, sr, sc+1, newColor, vis);
        
        if(sc-1>=0 && image[sr][sc]==image[sr][sc-1])
            solve(image, sr, sc-1, newColor, vis);
        
        if(sr+1<m && image[sr][sc]==image[sr+1][sc])
            solve(image, sr+1, sc, newColor, vis);
        
        if(sr-1>=0 && image[sr][sc]==image[sr-1][sc])
            solve(image, sr-1, sc, newColor, vis);
        
        image[sr][sc]=newColor;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m= image.size(), n= image[0].size();

        
        vector<vector<bool>> vis(m , vector<bool>(n, false));
        
        solve(image, sr, sc, newColor, vis);
        return image;
    }
};