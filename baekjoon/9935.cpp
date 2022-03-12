#include <bits/stdc++.h>
using namespace std;
stack<pair<char, int> > st;
vector<int> getSuffix(string &e){
    int m = e.size(), j = 0;
    vector<int> suf(m, 0);
    for(int i = 1; i<m; i++){
        while(j>0 && e[i] != e[j]){
            j = suf[j-1];
        }
        if(e[i] == e[j]){
            suf[i] = ++j;
        }
    }
    return suf;
}
void kmp(string &s, string &e, vector<int> &suf){
    int n = s.size(), m = e.size(), j = 0, i = 0;
    while(i!=n){
        while(j>0 && s[i] != e[j]){
            j = suf[j-1];
        }
        if(s[i]==e[j]){
            if(j==m-1){
                j = suf[j];
                for(int k = 0; k<m-1; k++){
                    st.pop();
                }
                j = st.empty()?0:st.top().second;
            }else{
                j++;
                st.emplace(s[i], j);
            }
        }else{
            st.emplace(s[i], j);
        }
        i++;
    }
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    string s, e;
    cin>>s>>e;
    auto suf = getSuffix(e);
    kmp(s, e, suf);
    s = "";
    while(!st.empty()){
        s+=st.top().first;
        st.pop();
    }
    reverse(s.begin(), s.end());
    s = s.compare("")==0?"FRULA":s;
    cout<<s;
    return 0;
}