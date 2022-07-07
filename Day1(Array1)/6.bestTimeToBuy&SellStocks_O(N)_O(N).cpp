#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //suffix max type;
        int n= prices.size();
        stack<int> st;
        int maxProf=0;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && prices[i]>st.top())
                st.pop();
            if(!st.empty()){
                maxProf= max(maxProf, st.top()-prices[i]);
                // cout<<prices[i]<<" "<<st.top()<<endl;
            } else
                st.push(prices[i]);
        }
        return maxProf;
    }
};