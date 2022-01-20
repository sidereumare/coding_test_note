#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;
int dist[1000][3];
int dp[3][1000][3] = {0,};
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<3; j++){
            cin>>dist[i][j];
        }
    }
    for(int i = 0; i<3; i++){
        dp[i][1][i] = INT32_MAX;
        dp[i][1][(i+1)%3] = dist[0][i]+dist[1][(i+1)%3];
        dp[i][1][(i+2)%3] = dist[0][i]+dist[1][(i+2)%3];
        for(int j = 2; j<N-1; j++){
            for(int k = 0; k<3; k++){
                dp[i][j][k] = min(dp[i][j-1][(k+1)%3], dp[i][j-1][(k+2)%3])+dist[j][k];
            }
        }
    }
    for(int i = 0; i<3; i++){
        for(int k = 0; k<3; k++){
            if(i==k){
                continue;
            }
            dp[i][N-1][k] = min(dp[i][N-2][(k+1)%3], dp[i][N-2][(k+2)%3])+dist[N-1][k];
        }
    }
    int m = INT32_MAX;
    for(int i = 0; i<3; i++){
        for(int k = 0; k<3; k++){
            if(i==k){
                continue;
            }
            m = min(dp[i][N-1][k], m);
        }
    }
    cout<<m;
    return 0;
}