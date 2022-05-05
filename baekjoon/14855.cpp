#include <bits/stdc++.h>
using namespace std;
int a[15], b[15], c[15], d[15], dp[11005][1005], n, m, p=1;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>m>>c[0]>>d[0];
    a[0]=100000;b[0]=1;
    for(int i = 1; i<=m; i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    for(int i = 0; i<=m; i++)
        for(int j = 0; j<min(a[i]/b[i], n/c[i]); j++){
            for(int k = c[i]; k<=n; k++)
                dp[i][k] = max(dp[i-1][k], dp[i-1][k-c[i]]+d[i]);
            p++;
        }
    cout<<dp[p-1][n];
    return 0;
}

