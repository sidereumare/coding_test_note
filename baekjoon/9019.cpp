#include <bits/stdc++.h>

using namespace std;
char before_op[10005];
int before_num[10005];
void init(){
    for(int i =0; i<10005; i++){
        before_num[i] = -1;
        before_op[i] = -1;
    }
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vector<function<pair<char, int>(int)> > func(
{[](int a){a = (a*2)%10000; return make_pair('D', a);},
[](int a){a = (a==0)?9999:a-1; return make_pair('S', a);},
[](int a){a = (a%1000*10)+(a/1000); return make_pair('L', a);},
[](int a){a = (a/10)+(a%10*1000); return make_pair('R', a);}});
    for(int T = 0; T<t; T++){
        init();
        int st, ta;
        bool flg = false;
        cin>>st>>ta;
        queue<int> q;
        q.emplace(st);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto &f: func){
                auto c = f(cur);
                if(before_op[c.second]==-1){
                    q.emplace(c.second);
                    before_num[c.second] = cur;
                    before_op[c.second] = c.first;
                    if(ta==c.second){
                        flg = true;
                        break;
                    }
                }
            }
            if(flg){
                break;
            }
        }
        ostringstream oss;
        int c = ta;
        while(c!=st){
            oss<<before_op[c];
            c = before_num[c];
        }
        string rst = oss.str();
        reverse(rst.begin(), rst.end());
        cout<<rst<<'\n';
    }
    return 0;
}