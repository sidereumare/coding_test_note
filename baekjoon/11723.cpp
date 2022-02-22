#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    bool s[21];
    unordered_map<string, int> m({{"all", 0},{"empty", 1},{"add", 2},{"remove", 3},{"check", 4}, {"toggle", 5} } );
    int M;
    cin>>M;
    for(int i = 0; i<M; i++){
        string op;
        int x;
        cin>>op;
        if(m[op]==0){
            for(int j = 1; j<=20; j++){
                s[j] = true;
            }
        }else if(m[op]==1){
            for(int j = 1; j<=20; j++){
                s[j] = false;
            }
        }else{
            cin>>x;
            if(m[op]==2){
                s[x] = true;
            }else if(m[op]==3){
                s[x] = false;
            }else if(m[op]==4){
                if(s[x]){
                    cout<<1<<'\n';
                }else{
                    cout<<0<<'\n';
                }
            }else {
                s[x] = s[x]?false:true;
            }
        }
    }
    return 0;
}