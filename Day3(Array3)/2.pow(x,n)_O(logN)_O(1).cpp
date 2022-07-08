#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double getPow(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        
        double temp=getPow(x, n/2);
        double ans= temp*temp;
        if(n%2==0) return ans;
        return ans*x;
    }
    double myPow(double x, int n) {
        double ans= getPow(x, n);
        if(n>0) return ans;
        return 1/ans;
    }
};