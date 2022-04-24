#include <bits/stdc++.h>

using namespace std;
int n, l, r, x, arr[16], rst = 0;
void sol(int p, int min_, int max_, int sum, bool chk){
    if(chk&&sum>=l&&sum<=r&&max_-min_>=x)
        rst++;
    if(p>=n)
        return;
    sol(p+1, min_, max_, sum, false);
    sol(p+1, min(min_, arr[p]), max(max_, arr[p]), sum+arr[p], true);
}
int main(){
    cin>>n>>l>>r>>x;
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    sol(0, 100000000, -1, 0, false);
    cout<<rst;
    return 0;
}