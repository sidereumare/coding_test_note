#include <bits/stdc++.h>
using namespace std;
int m[18][18], N, cnt[18][18][3];//i, j, 상태:0:가로, 1:대각, 2:세로
bool chkBound(int y, int x){
    return y<N&&y>=0&&x<N&&x>=0;
}
int main(){
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>m[i][j];
        }
    }
    memset(cnt, 0, sizeof(int)*18*18*3);
    cnt[0][1][0] = 1;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(m[i][j]!=1){
                if(chkBound(i, j-1)){
                    cnt[i][j][0] += cnt[i][j-1][0];
                    cnt[i][j][0] += cnt[i][j-1][1];
                }
                if(chkBound(i-1, j)){
                    cnt[i][j][2] += cnt[i-1][j][1];
                    cnt[i][j][2] += cnt[i-1][j][2];
                }
            }
            if(m[i][j]!=1&&chkBound(i-1, j)&&chkBound(i, j-1)&&chkBound(i-1, j-1)&&m[i][j-1]!=1&&m[i-1][j]!=1){
                cnt[i][j][1] += cnt[i-1][j-1][0];
                cnt[i][j][1] += cnt[i-1][j-1][1];
                cnt[i][j][1] += cnt[i-1][j-1][2];
            }
        }
    }
    cout<<cnt[N-1][N-1][0]+cnt[N-1][N-1][1]+cnt[N-1][N-1][2];

    return 0;
}