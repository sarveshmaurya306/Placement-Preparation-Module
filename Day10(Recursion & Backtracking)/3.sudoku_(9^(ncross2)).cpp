#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
    bool solve(vector<vector<char>>& board, int i, int j){        
        if(j==9){
            i++;
            j=0;
        }
        
        if(i==9 && j==0){
            return true;
        }
        
        if(board[i][j]!='.') {
            return solve(board, i, j+1);
        }
        
        for(char r='1'; r<='9'; r++){
            if(isOk(board, i, j, r)){
                board[i][j]=r;
                if(solve(board, i, j+1)) return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    
    bool isOk(vector<vector<char>>& board, int row, int col, char fill){
        for(int i=0;i<9;i++){
            if(board[i][col]==fill) return false;
            else if(board[row][i]==fill) return false;
            
            int r= 3*(row/3) + i/3;
            int c= 3*(col/3) + i%3;
            if(board[r][c]==fill) return false;
        }
        
        return true;
    }
};