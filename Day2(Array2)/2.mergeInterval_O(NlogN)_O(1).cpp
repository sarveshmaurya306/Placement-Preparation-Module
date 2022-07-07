#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(begin(in), end(in));
        //only four case posible after sorting
        //1) total ovelapping
        //2) partial overlapping
        //3) no overlapping
        //4) start just after
        
        int n= in.size();
        
        vector<vector<int>> ans;
        ans.push_back(in[0]);
        
        for(int i=1;i<n;i++){
            auto it= ans.back();
            ans.pop_back();
            
            int start1= it[0], end1= it[1];
            int start2= in[i][0], end2= in[i][1];
            
            if(start2 ==start1 && end1==end2){//case 1
                ans.push_back({start1, end1});
                continue;
            }
            else if(start2<end1){ //case2
                ans.push_back({start1, max(end1, end2)});
            } 
            else if(start2>end1){ //case 3
                ans.push_back(it);
                ans.push_back(in[i]);
            } 
            else if(start2==end1){ //case 4
                ans.push_back({start1, end2});
            }
        }
        
        return ans;
    }
};