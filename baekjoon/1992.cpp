#include <bits/stdc++.h>
using namespace std;
char pic[65][65];
string result = "";
void comp(int sx, int sy, int size){
    char start = pic[sy][sx];
    bool flg = true;
    for(int i = sy; i<sy+size; i++){
        for(int j = sx; j<sx+size; j++){
            if(start!=pic[i][j]){
                flg = false;
            }
        }
        if(!flg){
            break;
        }
    }
    if(flg){
        result += start;
        return;
    }
    result += "(";
    int nx = sx, ny = sy, nsize = size/2;
    for(int i = 1; i<=4; i++){
        comp(nx, ny, nsize);
        nx = i%2==0?sx:nx+nsize;
        ny = i%2==0?ny+nsize:ny;
    }
    result += ")";
}
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    int N;
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>pic[i][j];
        }
    }
    comp(0, 0, N);
    cout<<result;
    return 0;
}