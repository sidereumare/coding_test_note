#include <bits/stdc++.h>
using namespace std;
int N, M, rst;
vector<bool> broken(10, false);
pair<bool, int> chk(int n){
    string s = to_string(n);
    for(char &c: s){
        if(broken[c-'0']){
            return {false, s.length()};
        }
    }
    return {true, s.length()};
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i = 0; i<M; i++){
        int t;
        cin>>t;
        broken[t] = true;
    }
    rst = abs(N-100);
    for(int i = 0; i<1000000; i++){
        auto r = chk(i);
        if(r.first){
            rst = min(rst, r.second+abs(N-i));
        }
    }
    cout<<rst;
    return 0;
}