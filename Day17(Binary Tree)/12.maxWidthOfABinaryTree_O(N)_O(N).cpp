#include<bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, ll> > q;
        q.push({root, 0});
            
        int maxi=0;
        
        while(!q.empty()){
            int start, end;
            int prevLevelMin=q.front().second;
            int size= q.size();
            
            for(int i=0;i<size;i++){
                auto top= q.front(); q.pop();
                if(i==0) start= top.second;
                if(i==size-1) end= top.second;
                
                ll ind= top.second-prevLevelMin; //doing this to avoid int overflow
                ll leftInd= 2*ind+1, rightInd= 2*ind+2;
                
                if(top.first->left){
                    q.push({top.first->left, leftInd});
                }
                if(top.first->right){
                    q.push({top.first->right, rightInd});
                }
            }
            maxi=max(maxi, end-start+1);
        }
        return maxi;
    }
};