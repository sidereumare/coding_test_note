#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    int N, rst = 0;
    cin>>N;
    vector<int> t(N);
    for(int i = 0; i<N; i++){
        cin>>t[i];
    }
    sort(t.begin(), t.end());
    for(int i = 0; i<N; i++){
        rst+=(N-i)*t[i];
    }
    cout<<rst;
    return 0;
}