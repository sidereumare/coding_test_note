#include <iostream>
using namespace std;
int dp[205][205];
int main(){
    int N, K, sum;
    cin>>N>>K;
    dp[0][0]=1;
    for(int i = 1; i<=K; i++){
        sum=0;
        for(int j = 0; j<=N; j++){
            sum=(sum+dp[i-1][j])%1000000000;
            dp[i][j]=sum;
        }
    }
    cout<<dp[K][N];
    return 0;
}

/////////////
// #include <iostream>

// using namespace std;
// int dp[205][205];
// //i:k개, j:합, dp[i][j]:k개로 n이 나오는 가지 수
// //dp[i][j] = sum(dp[i-1][0~j])
// int main(){
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);
//     int N, K;
//     cin>>N>>K;
//     for(int i = 0; i<205; i++){
//         dp[1][i] = 1;
//     }
//     for(int i = 2; i<=K; i++){
//         int sum = 0;
//         for(int j = 0; j<=N; j++){
//             sum = (sum+dp[i-1][j])%1000000000;
//             dp[i][j]=sum;
//         }
//     }
//     cout<<dp[K][N];
//     return 0;
// }