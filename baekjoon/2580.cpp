#include <bits/stdc++.h>

using namespace std;
int board[9][9];
bool isvalid(int y, int x, int t){
    for(int i = 0; i<9; i++)
        if(board[i][x]==t)
            return false;
    for(int i = 0; i<9; i++)
        if(board[y][i]==t)
            return false;
    int by=y/3*3, bx=x/3*3;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(board[i+by][j+bx]==t){
                return false;
            }
        }
    }
    return true;
}
pair<int, int> nxt(int y, int x){
    int i, j;
    for(i = y; i<9; i++){
        j = i==y?x+1:0;
        for(; j<9; j++){
            if(board[i][j]==0){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
bool chk(int y, int x){
    if(y==-1){
        return true;
    }
    auto next = nxt(y, x);
    for(int i = 1; i<=9; i++){
        if(isvalid(y, x, i)){
            board[y][x] = i;
            if(chk(next.first, next.second)){
                return true;
            }
        }
        board[y][x] = 0;
    }
    return false;
}
int main(){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cin>>board[i][j];
        }
    }
    auto n = nxt(0,-1);
    chk(n.first, n.second);
    cout<<'\n';
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}