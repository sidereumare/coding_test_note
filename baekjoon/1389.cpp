#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    int N, M, dist[101][101], sum[101];
    cin>>N>>M;
    for(int i = 0; i<101; i++){
        for(int j = 0; j<101; j++){
            if(i==j){
                dist[i][j] = 0;
            }else{
                dist[i][j] = 200000000;
            }
        }
        sum[i] = 0;
    }
    for(int i = 0; i<M; i++){
        int a, b;
        cin>>a>>b;
        dist[a][b] = dist[b][a] = 1;
    }
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            sum[i] += dist[i][j];
        }
    }
    int m = INT32_MAX, rst;
    for(int i = 1; i<=N; i++){
        if(m>sum[i]){
            rst = i;
            m = sum[i];
        }
    }
    cout<<rst;
    return 0;
}