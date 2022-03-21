#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef unsigned long long ull;
ull powfast(ull n, int r){
    if(r==0){
        return 1;
    }
    ull h = powfast(n, r/2);
    return h*h% MOD * (r%2==1?n:1) %MOD;
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int M;
    ull rst = 0;
    cin>>M;
    for(int test = 0; test<M; test++){
        ull N, S;
        cin>>N>>S;
        rst = (rst+(powfast(N, MOD-2)*S%MOD))%MOD;
    }
    cout<<rst;
    return 0;
}