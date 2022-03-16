#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef unsigned long long ll;
ll mul[4000005];
void init(){
    mul[0] = 1;
    for(int i = 1; i<4000005; i++)
        mul[i] = mul[i-1]*i%MOD;
}
ll fpow(ll b, int e){
    ll rst = 1;
    while(e){
        rst = e&1?rst*b%MOD:rst;
        e>>=1;
        b = b*b%MOD;
    }
    return rst;
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    ll M, N, K;
    init();
    cin>>M;
    for(int test = 0; test<M; test++){
        cin>>N>>K;
        cout<<mul[N]*fpow(mul[N-K], MOD-2)%MOD*fpow(mul[K], MOD-2)%MOD<<'\n';
    }
    return 0;
}