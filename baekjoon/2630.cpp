#include <iostream>

using namespace std;
int paper[129][129];
//p:0~3
pair<int, int> count_rst(int bx, int by, int size){
    int h = size/2;
    pair<int, int> rst(0, 0);
    int s = paper[by][bx];
    bool flg = true;
    for(int y = by; y<by+size; y++){
        for(int x = bx; x<bx+size; x++){
            if(s!=paper[y][x]){
                flg = false;
                break;
            }
        }
        if(!flg){
            break;
        }
    }
    if(flg){
        if(s==0){
            return {1, 0};
        }else{
            return {0, 1};
        }
    }
    for(int p = 0; p<4; p++){
        int sx = bx+(p%2==0?0:h), sy = by+(p/2==0?0:h);
        auto t = count_rst(sx, sy, h);
        rst.first+=t.first;
        rst.second+=t.second;
    }
    return rst;
}
int main(){
    int N;
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>paper[i][j];
        }
    }
    auto t = count_rst(0, 0, N);
    cout<<t.first<<'\n'<<t.second;
    return 0;
}