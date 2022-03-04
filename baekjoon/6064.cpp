#include <iostream>

using namespace std;
typedef long long ll;
pair<ll,pair<ll,ll>> xGCD(ll a, ll b) {
    if(b == 0) return {a,{1,0}};
    pair<ll,pair<ll,ll>> ret = xGCD(b, a%b);
    ll g, x, y;
    g = ret.first;
    x = ret.second.first;
    y = ret.second.second;
    return {g,{y,x-(a/b)*y}};   
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    ll n, m, x, y, t;
    cin>>t;
    for(int T = 0; T<t; T++){
        cin>>m>>n>>x>>y;
        ll a1 = x, a2 = y;
        ll m1 = m, m2 = n;
        ll g = __gcd(m1, m2);
        if(a1 % g != a2 % g) {
            cout<<"-1\n";
        }
        else{
            ll p, q;
            auto res = xGCD(m1/g, m2/g);
            p = res.second.first;
            q = res.second.second;
            ll mod = m1 / g * m2;
            a1 = ((((a1 * (m2/g) % mod)* q) % mod + ((a2*(m1/g)%mod)*p)% mod)+mod)%mod;
            cout<<a1<<'\n';
            a1 = (a1 + mod) % mod;
            m1 = mod;
        }
    }
    return 0;
}