#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, k, k_;
    cin>>n>>k;
    long long l = 1, idx = 9, cnt = 0;
    while(k>idx*l){
        k-=idx*l;
        l++;
        cnt+=idx;
        idx*=10;
    }
    cnt+=(k-1)/l+1;
    k%=l;
    if(cnt>n){
        cout<<-1;
    }else{
        if(k==0){
            cout<<to_string(cnt)[l-1];
        }else{
            cout<<to_string(cnt)[k-1];
        }
    }
    return 0;
}