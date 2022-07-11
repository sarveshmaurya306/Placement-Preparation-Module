#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n){
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int maxiPlt=0;
    	int currPlt=0;
    	
    	int i=0, j=0;
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]) {
    	        currPlt++;
    	        i++;
    	    }
    	    else if(arr[i]>dep[j]){
    	        currPlt--;
    	        j++;
    	    }
    	    maxiPlt=max(maxiPlt, currPlt);
    	}
    	return maxiPlt;
    }
};