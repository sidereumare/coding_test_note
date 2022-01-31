#include <iostream>
using namespace std;
int sum[1025][1025];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    cin>>N>>M;
    //부분합 구하기
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            int t;
            cin>>t;
            sum[i][j] = sum[i][j-1]+t;
        }
    }
    for(int i = 2; i<=N; i++){
        for(int j = 1; j<=N; j++){
            sum[i][j]+=sum[i-1][j];
        }
    }
    for(int i = 0; i<M; i++){
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<<'\n';
    }
    return 0;
}
