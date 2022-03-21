#include <bits/stdc++.h>

using namespace std;
int arr[8], pr[8], N, M;
void sequence(int before, int pos){
    if(pos==M){
        for(int i = 0; i<M; i++){
            cout<<pr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = before; i<N; i++){
        pr[pos] = arr[i];
        sequence(i, pos+1);
    }
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr, arr+N);
    sequence(0, 0);
    return 0;
}