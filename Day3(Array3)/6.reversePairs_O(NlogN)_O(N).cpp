#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int cnt=0;
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return cnt;
    }
    
    void cntRevPairs(vector<int>& arr, int start1, int end1, int start2, int end2){
        int j= start2;
        
        for(int i=start1;i<=end1;i++){
            while(j<=end2 && arr[i] > 2ll * arr[j]){
                j++;
            }
            cnt+= (j-start2);
        }
    }
    
    void merge(vector<int>& arr, int left, int right){
        ll mid= (left+right)/2;

        ll k=0;
        ll i=left;
        ll j=mid+1;
        
        //left, mid;  mid+1, right;
        cntRevPairs(arr, left, mid, mid+1, right); //!main fun doing main thing
        
        ll temp[right-left+1];

        while(i<=mid && j<=right){
            if(arr[i] <= arr[j]){
                temp[k++]=arr[i++];
            } else{
                temp[k++]=arr[j++];
            }
        }

        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=right){
            temp[k++]=arr[j++];
        }

        for(ll i=left;i<=right;i++){
            arr[i]=temp[i-left];
        }
    }

    void mergeSort(vector<int>& arr, int left, int right){
        if(left>=right) return;

        ll mid= (left+right)/2;

        //dividing step
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        //joining step
        merge(arr, left, right);

    }

};