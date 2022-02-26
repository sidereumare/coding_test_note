#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int N, M;
    cin>>N>>M;
    vector<int> sum(N+1, 0);
    cin>>sum[1];
    for(int i = 2; i<=N; i++){
        cin>>sum[i];
        sum[i] += sum[i-1];
    }
    for(int i = 0; i<M; i++){
        int a, b;
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<'\n';
    }
    return 0;
}