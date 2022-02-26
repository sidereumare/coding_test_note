#include <bits/stdc++.h>
using namespace std;
int paper[3000][3000];
int cnt[3] = {0,0,0};
void calc(int sx, int sy, int size){
    int start = paper[sy][sx];
    bool isOneColor = true;
    for(int i =sy; i<sy+size; i++){
        for(int j = sx; j<sx+size; j++){
            if(paper[i][j]!=start){
                isOneColor = false;
                break;
            }
        }
        if(!isOneColor){
            break;
        }
    }
    if(isOneColor){
        cnt[start+1]++;
        return;
    }
    int nx = sx, ny = sy, ns = size/3;
    for(int i = 1; i<=9; i++){
        calc(nx, ny, ns);
        nx = i%3==0?sx:nx+ns;
        ny = i%3==0?ny+ns:ny;
    }
    return;
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int N;
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>paper[i][j];
        }
    }
    calc(0, 0, N);
    cout<<cnt[0]<<'\n'<<cnt[1]<<'\n'<<cnt[2];
    return 0;
}