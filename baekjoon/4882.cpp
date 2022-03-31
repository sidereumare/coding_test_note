#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    string s;
    int cur = 1;
    while(true){
        cin>>s;
        if(s=="()"){
            break;
        }
        
        int l = 0, l_m = 0; bool chk = true;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='('){
                l++;
            }else if(s[i]==')'){
                l--;
            }
            l_m = max(l, l_m);
        }
        if(l_m%2==1){
            chk = false;
        }

        stack<char> st; int level = 0;
        bool t;
        for(char&c : s){
            if(c=='('){
                level++;
                st.emplace(c);
            }else if(c==')'){
                t = st.top()=='T'?true:false;
                st.pop();
                while(st.top()!='('){
                    bool n = st.top()=='T'?true:false;
                    t = (level%2==l_m%2)?n&&t:n||t;
                    st.pop();
                }
                st.pop();
                st.emplace((t==true?'T':'F'));
                level--;
            }else{
                st.emplace(c);
            }
        }
        if(st.top()=='T'){
            cout<<cur<<". true\n";
        }else{
            cout<<cur<<". false\n";
        }
        cur++;
    }
    return 0;
}