#include <bits/stdc++.h>
#define BEFORE 0
#define NEXT 1

using namespace std;
int sta[1000005][2], n, m, bef, nxt, st, a, b, i;
string q;
void ins(int b, int n, int j){
    sta[b][1] = j;
    sta[n][0] = j;
    sta[j][0] = b;
    sta[j][1] = n;
}
void cl(int i){
    sta[sta[i][0]][1] = sta[i][1];
    sta[sta[i][1]][0] = sta[i][0];
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>m;
    cin>>bef;
    st = bef;
    for(i = 1; i<n; i++){
        cin>>nxt;
        sta[bef][1] = nxt;
        sta[nxt][0] = bef;
        bef = nxt;
    }
    sta[st][0] = bef;
    sta[bef][1] = st;
    
    for(i = 0; i<m; i++){
        cin>>q>>a;
        if(q[1]=='N'){
            bef = a;
            nxt = sta[a][1];
            cout<<nxt<<'\n';
        }else{
            bef = sta[a][0];
            nxt = a;
            cout<<bef<<'\n';
        }
        if(q[0]=='B'){
            cin>>b;
            ins(bef, nxt, b);
        }else{
            cl(a==bef?nxt:bef);
        }
    }
    return 0;
}