#include <bits/stdc++.h>

using namespace std;
int main(){
    int N;
    cin>>N;
    map<char, int> m;
    for(int i = 0; i<N; i++){
        string s;
        cin>>s;
        int idx = 1;
        reverse(s.begin(), s.end());
        for(int i = 0; i<s.length(); i++){
            m[s[i]] += idx;
            idx*=10;
        }
    }
    vector<int> r;
    for(auto &s: m){
        r.emplace_back(s.second);
    }
    sort(r.begin(), r.end());
    int rst = 0, idx = 9;
    for(int i = r.size()-1; i>=0; i--){
        rst+=r[i]*idx;
        idx--;
    }
    cout<<rst;
    return 0;
}