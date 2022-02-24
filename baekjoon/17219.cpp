#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false); cout.tie(NULL);
    int N, M;
    unordered_map<string, string> dic;
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        string s, pw;
        cin>>s>>pw;
        dic.emplace(s, pw);
    }
    for(int i = 0; i<M; i++){
        string q;
        cin>>q;
        cout<<dic[q]<<'\n';
    }
    return 0;
}