#include <bits/stdc++.h>
#define INF 100000000
using namespace std;
vector<vector<pair<int, int> > > adj;
int N, M, W, u, v, w, T;
bool bellman(int st){
    vector<int> upper(N+2, INF);
    upper[st] = 0;
    bool updated;
    for(int i = 1; i<=N; i++){
        updated = false;
        for(int j = 1; j<=N; j++){
            if(upper[j]==INF) continue;
            for(auto c: adj[j]){
                int n = c.first;
                int cost = c.second;
                if(upper[n]>upper[j]+cost){
                    upper[n] = upper[j]+cost;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }
    return updated || upper[st]<0;
}
int main(){
    cin>>T;
    for(int t = 0; t<T; t++){
        cin>>N>>M>>W;
        adj.assign(N+2, vector<pair<int, int> >());
        for(int i = 0; i<M; i++){
            cin>>u>>v>>w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        for(int i = 0; i<W; i++){
            cin>>u>>v>>w;
            adj[u].emplace_back(v, -w);
        }
        bool chk = false;
        for(int i = 1; i<=N; i++){
            if(bellman(i)){
                chk = true;
                break;
            }
        }
        if(chk) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}