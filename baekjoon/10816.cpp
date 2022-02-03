#include <iostream>
#include <vector>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, t;
    cin>>N;
    vector<int> cnt(20000002, 0);
    for(int i = 0; i<N; i++){
        cin>>t;
        cnt[t+10000000]++;
    }
    cin>>M;
    for(int i = 0; i<M; i++){
        cin>>t;
        cout<<cnt[t+10000000]<<' ';
    }
    return 0;
}