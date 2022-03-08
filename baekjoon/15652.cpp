#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> before(9, 0);
void prnm(int b, int remain){
    if(remain==0){
        for(int i = 0; i<M; i++){
            cout<<before[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = b; i<=N; i++){
        before[M-remain] = i;
        prnm(i, remain-1);
    }
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>N>>M;
    prnm(1, M);
    return 0;
}