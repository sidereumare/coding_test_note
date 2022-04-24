#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n, l, a[1005];
    cin>>n>>l;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    sort(a, a+n);
    int cnt = 0, st = -500000;
    for(int i = 0; i<n; i++){
        if(a[i]-st>=l){
            st = a[i];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}