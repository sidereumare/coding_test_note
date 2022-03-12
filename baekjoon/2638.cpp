#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int cheese[105][105], N, M;
vector<pair<int, int> > mv({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
set<pair<int, int> > removed;
void clr(){
    for(auto &r: removed){
        cheese[r.X][r.Y] = 0;
    }
    removed.clear();
}
bool chk_bound(pair<int, int> &p){
    return p.X<N && p.X>=0 && p.Y<M && p.Y>=0;
}
void bfs(){
    queue<pair<int, int> > q;
    vector<vector<int> > cnt(N, vector<int>(M, 0));
    q.emplace(0, 0);
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto &n: mv){
            auto nxt = make_pair(cur.X+n.X, cur.Y+n.Y);
            if(chk_bound(nxt)){
                if(cnt[nxt.X][nxt.Y]==0 && cheese[nxt.X][nxt.Y]==0){
                    q.emplace(nxt);
                }
                cnt[nxt.X][nxt.Y]++;
                if(cnt[nxt.X][nxt.Y]>=2 && cheese[nxt.X][nxt.Y]==1){
                    removed.insert(nxt);
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int cnt = 0, rst = 0;
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>cheese[i][j];
            if(cheese[i][j]==1){
                cnt++;
            }
        }
    }
    while(cnt!=0){
        bfs();
        cnt-=removed.size();
        clr();
        rst++;
    }
    cout<<rst;
    return 0;
}