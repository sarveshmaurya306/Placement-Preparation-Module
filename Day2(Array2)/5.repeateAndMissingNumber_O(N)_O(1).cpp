#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::repeatedNumber(const vector<int> &a) {
    int n= a.size();
    //step1 xor of all ele and 1-n numbers
    int xXory=0;
    for(int i=1;i<=n;i++) {
        xXory^=i;
        xXory^=a[i-1];
    }
    
    //x^y=7; got
    //step2 finding the last set bit position
    int lastSetBitPos=0;
    while(xXory>0){
        xXory/=2;
        lastSetBitPos++;
    }
    
    //step3 now saparate in two buckets;
    lastSetBitPos--;
    int buc1=0, buc2=0; //ele having last bit set in buc1 otherwise buc2
        //also doing same with 1-n numbers
    for(int i=1;i<=n;i++){
        if(i&(1<<lastSetBitPos)) buc1^=i;
        else buc2^=i;
    }
    
    for(int i=0;i<n;i++){
        if(a[i]&(1<<lastSetBitPos)) buc1^=a[i];
        else buc2^=a[i];
    }
    
    //buc1 and buc2 will have 1-1 number 1missing 1repeating
    //step4 saparating/identifing the missing and repeating number
    
    //ans formate , appears twice -> missing;
    for(int i: a){
        if(i==buc1) return {buc1, buc2};
        if(i==buc2) return {buc2, buc1};
    }
    return {};
}
