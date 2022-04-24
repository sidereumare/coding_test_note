#include <bits/stdc++.h>

using namespace std;
int sum[200005][26];
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    string s;
    int q;
    cin>>s;
    cin>>q;
    sum[0][s[0]-'a'] = 1;
    for(int i = 1; i<s.length(); i++){
        for(int j = 0; j<26; j++){
            sum[i][j] = sum[i-1][j];
        }
        sum[i][s[i]-'a']++;
    }
    for(int query = 0; query<q; query++){
        char c;
        int s, e;
        cin>>c>>s>>e;
        if(s==0){
            cout<<sum[e][c-'a']<<'\n';
        }else{
            cout<<sum[e][c-'a']-sum[s-1][c-'a']<<'\n';
        }
    }
    return 0;
}