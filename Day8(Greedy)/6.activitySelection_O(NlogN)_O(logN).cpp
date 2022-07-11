#include<bits/stdc++.h>
using namespace std;

/*
struct Item{
    int value;
    int weight;
};
*/
class Solution{
    public:
    bool static comp(Item &a, Item &b){
        //value/wt;
        return a.value*b.weight> b.value*a.weight;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr+n, comp);
        
        double prof=0;
        for(int i=0;i<n;i++){
            if(W-arr[i].weight >=0){
                prof+= arr[i].value;
                W-=arr[i].weight;
            } else{
                prof+= ((double)arr[i].value/(double)arr[i].weight) * W;
                break;
            }
        }
        return prof;
    }
};
