#include<bits/stdc++.h>
using namespace std;

long double findVal(long double mid, int n){
    long double temp=1.0;
    
    while(n--){
        temp*= mid;
    }
    return temp;
}

double findNthRootOfM(int n, int m) {
    long double lo= 1, hi= m, ep= 1e-8;
    while(hi-lo>ep){
        long double mid= lo+(hi-lo)/2.0;
        long double val= findVal(mid, n);
        if(val > m) hi=mid;
        else lo=mid;
    }
    return lo;
}

int main(){
    int n,m; cin>>n>>m;	
    cout<<findNthRootOfM(n, m);
}
