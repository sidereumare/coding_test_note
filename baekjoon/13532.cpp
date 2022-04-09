#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
pair<ld, int> chk(int n){
    int cnt = 0;
    ld l = (ld)2/(ld)3;
    for(int i = 0; i<n; i++){
        l/=(ld)2;
        while(l<(ld)0.1) {l*=10; cnt++;}
    }
    return { l, cnt};
}
int main(){
    int n;
    cin>>n;
    if(n<2){
        cout<<0;
        return 0;
    }
    auto c = chk(n);
    //-
    if(n%2==0){
        c.first = (ld)2/(ld)3 - c.first;
        if(c.first<0){
            c.second--;
        }
    }
    //+
    else{
        c.first = (ld)2/(ld)3 + c.first;
        if(c.first>=1){
            c.second--;
        }
    }
    while(c.first>=(ld)0.6 && c.first<(ld)0.7){c.first*=10; c.first-=6; c.second++;}
    cout<<c.second;
    return 0;
}