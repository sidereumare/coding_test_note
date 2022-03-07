#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
vector<int> dp(1001, INF);
vector<vector<pair<int, int> > > m;
void dij(int start){
    priority_queue<pair<int, int>> pq;
    dp[start] = 0;
    pq.emplace(0, start);
    while(!pq.empty()){
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if(dp[current]<cost) continue;
        for(auto &n: m[current]){
            int ncost = cost+n.second;
            if(dp[n.first]>ncost){
                dp[n.first] = ncost;
                pq.emplace(-ncost, n.first);
            }
        }
    }
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int N, M, st, end, a, b, c;
    cin>>N>>M;
    m.assign(N+1, vector<pair<int, int> >());
    for(int i = 0; i<M; i++){
        cin>>a>>b>>c;
        m[a].emplace_back(b, c);
    }
    cin>>st>>end;
    dij(st);
    cout<<dp[end];
    return 0;
}