#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void solve(vector<int>& arr, vector<int>& ans, int i, int sum=0){
        if(i==arr.size()) {
            ans.push_back(sum);
            return;
        }
        solve(arr, ans, i+1, sum+ arr[i]);
        solve(arr, ans, i+1, sum);
    }

    vector<int> subsetSums(vector<int> arr, int N){
        // Write Your Code here
        vector<int> ans;
        solve(arr, ans, 0);
		sort(begin(ans), end(ans));
        return ans;
    }
};