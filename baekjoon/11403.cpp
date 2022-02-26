#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int N, adj[101][101];
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>adj[i][j];
        }
    }
    for(int k = 0; k<N; k++){
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                adj[i][j] = (adj[i][k]==1&&adj[k][j]==1)||(adj[i][j]==1)?1:0;
            }
        }
    }
    for(int i =0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout<<adj[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}