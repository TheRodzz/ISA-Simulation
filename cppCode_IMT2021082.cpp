#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll fib(ll n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fib(n-1)+fib(n-2);
}

int main(){
    ll n;
    cin>>n;
    cout<<fib(n);
}

