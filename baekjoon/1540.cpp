#include <bits/stdc++.h>
using namespace std;int main(){int n,q,r;cin>>n;q=(int)sqrt(n)-1;r=n-(q+1)*(q+1);cout<<q*(q+1)*(2*q+1)/6+((r>q+1)?q*(q+1)/2+(r-q-1)*(r-q-2)/2:(r-1)*r/2);return 0;}