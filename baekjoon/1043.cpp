#include <bits/stdc++.h>
using namespace std;
vector<bool> chk(51, false);
vector<pair<vector<int>, bool> > party;
void checkParty(){
    for(auto& p: party){
        for(auto &c: p.first){
            if(chk[c]){
                p.second = true;
                break;
            }
        }
    }
}
void updateChk(){
    for(auto &p: party){
        if(p.second){
            for(auto &c: p.first){
                chk[c] = true;
            }
        }
        p.second = false;
    }
}
int main(){
    int N, M, cnt, rst = 0;
    cin>>N>>M>>cnt;
    for(int i = 0; i<cnt; i++){
        int c;
        cin>>c;
        chk[c] = true;
    }
    party.assign(M, {vector<int>(), false});
    for(int i = 0; i<M; i++){
        cin>>cnt;
        party[i].first.assign(cnt, 0);
        for(int &c: party[i].first){
            cin>>c;
            if(chk[c]){
                party[i].second = true;
            }
        }
    }
    for(int i = 0; i<M; i++){
        checkParty();
        updateChk();
    }
    for(auto& p: party){
        bool flg = true;
        for(auto &c: p.first){
            if(chk[c]){
                flg = false;
                break;
            }
        }
        if(flg&&p.first.size()>0){
            rst++;
        }
    }
    cout<<rst;
    return 0;
}