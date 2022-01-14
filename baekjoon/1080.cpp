#include <iostream>
#include <string>
#include <vector>
using namespace std;

void conversion(vector<string>& A, int x, int y){
    for(int i = x; i<x+3; i++){
        for(int j = y; j<y+3; j++){
            if(A[i][j]=='0'){
                A[i][j] = '1';
            }else{
                A[i][j] = '0';
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    vector<string> A, B;
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        string t;
        cin>>t;
        A.push_back(t);
    }
    for(int i = 0; i<N; i++){
        string t;
        cin>>t;
        B.push_back(t);
    }
    int cnt = 0;
    for(int i = 0; i<N-2; i++){
        for(int j = 0; j<M-2; j++){
            if(A[i][j]!=B[i][j]){
                cnt++;
                conversion(A, i, j);
            }
        }
    }

    bool chk = true;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(A[i][j]!=B[i][j]){
                chk = false;
            }
        }
    }
    cnt = chk?cnt:-1;
    cout<<cnt;
    return 0;
}