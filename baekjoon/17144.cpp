#include <bits/stdc++.h>

using namespace std;
int R, C, T, room[51][51], roomt[51][51];
int px, py, mx[4] = {0,0,-1,1}, my[4] = {1, -1, 0, 0};
bool chkBound(int y, int x){
    return y>=0 && y<R && x>=0 && x<C && room[y][x]!=-1;
}
void diffusion(){
    memset(roomt, 0, 51*51*sizeof(int));
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            int cnt = 0;
            for(int k = 0; k<4; k++){
                int nx = j+mx[k], ny = i+my[k];
                if(chkBound(ny, nx) && room[i][j]>=5){
                    cnt++;
                    roomt[ny][nx] += room[i][j]/5;
                }
            }
            roomt[i][j] += room[i][j]-(room[i][j]/5*cnt);
        }
    }
    swap(room, roomt);
}
void purify(){
    for(int y = py-2; y>0; y--){
        room[y][px] = room[y-1][px];
    }
    for(int x = px; x<C-1; x++){
        room[0][x] = room[0][x+1];
    }
    for(int y = 0; y<py-1; y++){
        room[y][C-1] = room[y+1][C-1];
    }
    for(int x = C-1; x>1; x--){
        room[py-1][x] = room[py-1][x-1];
    }
    room[py-1][1]=0;

    for(int y = py+1; y<R-1; y++){
        room[y][px] = room[y+1][px];
    }
    for(int x = px; x<C-1; x++){
        room[R-1][x] = room[R-1][x+1];
    }
    for(int y = R-1; y>py; y--){
        room[y][C-1] = room[y-1][C-1];
    }
    for(int x = C-1; x>1; x--){
        room[py][x] = room[py][x-1];
    }
    room[py][1]=0;
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>R>>C>>T;
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cin>>room[i][j];
            if(room[i][j]==-1){
                px = j; py = i;
            }
        }
    }
    for(int t = 0; t<T; t++){
        diffusion();
        purify();
    }
    int sum = 0;
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(room[i][j]!=-1){
                sum+=room[i][j];
            }
        }
    }
    cout<<sum;
    return 0;
}