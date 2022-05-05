#include <bits/stdc++.h>
using namespace std;
vector<unsigned int> t(100005, 0);
unordered_set<unsigned int> s;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int q, a, b;
        cin>>q>>a;
        if(q==1){
            cin>>b;
            t[a] |= 1<<b;
        }else if(q==2){
            cin>>b;
            t[a] &= ~(1<<b);
        }else if(q==3){
            t[a] <<= 1;
            t[a] &= ~(1<<21);
        }else{
            t[a] >>= 1;
            t[a] &= ~1;
        }
    }
    for(int i = 1; i<=n; i++){
        s.insert(t[i]);
    }
    cout<<s.size();
    return 0;
}