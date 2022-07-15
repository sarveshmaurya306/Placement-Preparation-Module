/************************************************************
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
************************************************************/
//ON GFG

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int leftest ,rightest;
    
    void solve(Node *root, unordered_map<int, pair<int,int>> &mp, int ind, int level){
		if(!root) return;
	
		solve(root->left, mp, ind-1, level+1);
		solve(root->right, mp, ind+1, level+1);
	
		leftest= min(leftest, ind);
		rightest= max(rightest, ind);
	
		if(mp.find(ind)!=mp.end()){ //present
			// level must be lesser in order to replace
			auto curr= mp[ind];
			if(curr.first > level)  //!!! same as bottomView only change here
				mp[ind]={level, root->data};
		} else // not present
			mp[ind]={level, root->data};
	}

    vector<int> topView(Node *root){
        unordered_map<int, pair<int,int> > mp; // ind, <level, value> 
        
        leftest=INT_MAX;
        rightest= INT_MIN;
    
        solve(root, mp, 0, 0);
        vector<int> ans;
    
        for(int i=leftest;i<=rightest;i++)
            if(mp.find(i)!=mp.end())
                ans.push_back(mp[i].second);
    
        //O(N) & O(N)
        return ans;
    }

};
