#include <bits/stdc++.h>

using namespace std;
string s;
int cnt[26];
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>s;
    for(char &c: s)
        cnt[c-'A']++;
    ostringstream oss;
    int m = -1;
    for(int i = 0; i<26; i++){
        for(int j = 0; j<cnt[i]/2; j++)
            oss<<(char)(i+'A');
        if(m==-1 && cnt[i]%2==1){
            m = i;
        }else if(cnt[i]%2==1){
            cout<<"I\'m Sorry Hansoo";
            return 0;
        }
    }
    s = oss.str();
    if(m!=-1)
        oss<<(char)(m+'A');
    reverse(s.begin(), s.end());
    oss<<s;
    cout<<oss.str();
    return 0;
}