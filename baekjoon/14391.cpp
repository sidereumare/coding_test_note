#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int N, M, paper[4][4], rst = 0;
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        string s;
        cin>>s;
        for(int j = 0; j<M; j++){
            paper[i][j] = s[j]-'0';
        }
    }

    //비트마스킹 이용
    //1->세로, 0->가로
    for(int c=0; c<(1<<(N*M)); c++){
        int sum = 0;
        //가로
        for(int i = 0; i<N; i++){
            int row = 0;
            for(int j = 0; j<M; j++){
                int k = i*M+j;
                if((c&(1<<k)) == 0){
                    row = row*10+paper[i][j];
                }else{
                    sum+=row;
                    row = 0;
                }
            }
            sum+=row;
        }

        //세로
        for(int i = 0; i<M; i++){
            int col = 0;
            for(int j = 0; j<N; j++){
                int k = j*M+i;
                if((c&(1<<k)) != 0){
                    col = col*10+paper[j][i];
                }else{
                    sum+=col;
                    col = 0;
                }
            }
            sum+=col;
        }
        rst = max(rst, sum);
    }
    cout<<rst;
    return 0;
}