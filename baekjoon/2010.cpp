#include <bits/stdc++.h>

using namespace std;
int n, sum=0;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 0; i<n; i++){
        int t;
        cin>>t;
        sum+=t;
    }
    cout<<sum-n+1;
    return 0;
}