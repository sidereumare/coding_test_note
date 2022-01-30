//냅색
//dp[i][j]: i까지 물건을 살펴보고 배낭 용량이 j일때 가치합의 최댓값
//dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i])
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int weight[101], value[101], dp[101][100001];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, K;
    cin>>N>>K;
    for(int i = 1; i<=N; i++){
        cin>>weight[i]>>value[i];
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=K; j++){
            if(j-weight[i]>=0){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=K; j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<dp[N][K];
    return 0;
}