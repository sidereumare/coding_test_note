#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
vector<int> dp, before, route;
void dij(int s, vector<vector<pair<int, int> > > &m){
    priority_queue<pair<int, int> > pq;
    dp.assign(m.size(), INF);
    before.assign(m.size(), -1);
    dp[s] = 0;
    pq.emplace(0, s);
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(cost>dp[cur]) continue;
        for(auto &nxt: m[cur]){
            int ncost = cost+nxt.second;
            if(dp[nxt.first]>ncost){
                dp[nxt.first] = ncost;
                before[nxt.first] = cur;
                pq.emplace(-ncost, nxt.first);
            }
        }
    }
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int N, M, s, e, a, b, c;
    cin>>N>>M;
    vector<vector<pair<int, int> > > m(N+1, vector<pair<int,int> >());
    for(int i = 0; i<M; i++){
        cin>>a>>b>>c;
        m[a].emplace_back(b, c);
    }
    cin>>s>>e;
    dij(s, m);
    while(s!=e){
        route.emplace_back(e);
        e = before[e];
    }
    route.emplace_back(s);
    cout<<dp[route[0]]<<'\n'<<route.size()<<'\n';
    for(auto it = route.rbegin(); it!=route.rend(); it++){
        cout<<*it<<' ';
    }
    return 0;
}