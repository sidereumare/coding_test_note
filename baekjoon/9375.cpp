#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int test;
    cin>>test;
    for(int test_case = 0; test_case<test; test_case++){
        int n;
        map<string, int> m;
        cin>>n;
        for(int i = 0; i<n; i++){
            string a, b;
            cin>>a>>b;
            auto it = m.find(b);
            if(it!=m.end()){
                it->second++;
            }else{
                m.emplace(b, 1);
            }
        }
        int rst = 1;
        for(auto &c: m){
            rst*=(c.second+1);
        }
        cout<<--rst<<'\n';
    }
    return 0;
}