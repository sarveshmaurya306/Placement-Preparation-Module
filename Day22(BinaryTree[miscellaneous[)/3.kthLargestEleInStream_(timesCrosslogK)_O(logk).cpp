#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;//min heap
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        for(int i: nums){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        this->k=k;
        // NlogN
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k) pq.pop();
        return pq.top();
        //logN
    }
};