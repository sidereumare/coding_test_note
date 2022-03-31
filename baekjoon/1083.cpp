#include <bits/stdc++.h>

using namespace std;

int arr[55];
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int N, cnt;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
    cin>>cnt;
    for(int i = 0; i<N-1 && cnt; i++){
        int m = arr[i], p = i;
        for(int j = i+1; j<N && j<=i+cnt; j++){
            if(m<arr[j]){
                m = arr[j];
                p = j;
            }
        }
        while(p>i){
            arr[p]=arr[p-1];
            p--;
            cnt--;
        }
        arr[i] = m;
    }
    for(int i = 0; i<N; i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}