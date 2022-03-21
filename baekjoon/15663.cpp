#include <bits/stdc++.h>

using namespace std;
int arr[8], pr[8], N, M;
bool chk[8];
void sequence(int pos){
    if(pos==M){
        for(int i = 0; i<M; i++){
            cout<<pr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = 0; i<N; i++){
        if(chk[i] || arr[i]==pr[pos]){
            continue;
        }
        pr[pos] = arr[i];
        chk[i] = true;
        sequence(pos+1);
        chk[i] = false;
    }
    pr[pos] = 0;
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        cin>>arr[i];
        chk[i] = false;
    }
    sort(arr, arr+N);
    sequence(0);
    return 0;
}