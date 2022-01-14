#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<long long> > dp(13, vector<long long>(13, 0));
vector<long long> cntPwd(13,0);
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    for(int i = 1; i<12; i++){
        cntPwd[i] += dp[i][1] = pow(2, i)-1;
        for(int j = 2; j<=i; j++){
            cntPwd[i] += dp[i][j] = dp[i-1][j-1]*j+dp[i-1][j]*(j+1);
        }
    }
    for(int i = 0; i<N; i++){
        int B;
        cin>>B;
        cout<<cntPwd[B]<<'\n';
    }
    return 0;
}