#include <bits/stdc++.h>

using namespace std;
bool chk[10005];
vector<int> p;
void eratos(){
    for(int i =0; i<10005; i++){
        chk[i] = true;
    }
    for(int i = 2; i*i<=10005; i++){
        if(chk[i]){
            for(int j = i*i; j<=10005; j+=i){
                chk[j] = false;
            }
        }
    }
    for(int i = 2; i<=10000; i++){
        if(chk[i]){
            p.emplace_back(i);
        }
    }
}
int main(){
    eratos();
    int m, n, m_;
    long long rst = 0;
    cin>>m>>n;
    auto it = lower_bound(p.begin(), p.end(), m);
    if(it==p.end()){
        cout<<-1;
        return 0;
    }
    m_=*it;
    while(*it<=n){
        rst+=(*it);
        it++;
    }
    if(rst==0){
        cout<<-1;
        return 0;
    }
    cout<<rst<<'\n'<<m_;
    return 0;
}