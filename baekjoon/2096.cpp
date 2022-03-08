#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int N, a, b, c, d, e, f;
    cin>>N>>a>>b>>c;
    int mn[3] = {a, b, c}, mx[3] = {a, b, c};
    for(int i = 1; i<N; i++){
        cin>>a>>b>>c;
        d = min(mn[0], mn[1])+a;
        e = min({mn[0], mn[1], mn[2]})+b;
        f = min(mn[1], mn[2])+c;
        mn[0] = d; mn[1] = e; mn[2] = f;
        d = max(mx[0], mx[1])+a;
        e = max({mx[0], mx[1], mx[2]})+b;
        f = max(mx[1], mx[2])+c;
        mx[0] = d; mx[1] = e; mx[2] = f;
    }
    cout<<max({mx[0], mx[1], mx[2]})<<' '<<min({mn[0], mn[1], mn[2]});
    return 0;
}