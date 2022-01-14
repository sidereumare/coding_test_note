#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <tuple>
using namespace std;

int N, M, K;
vector<vector<pair<int, long long> > > map;
//minTime[i][j]->i:포장한 도로 수, j:도시
vector<vector<long long> > minTime;

void dij(int start){
    minTime[0][start] = 0;
    //cost, next, 포장수
    priority_queue<tuple<long long, int ,int> > pq;
    pq.emplace(0, start, 0);
    while(!pq.empty()){
        int current, k;
        long long cost;
        tie(cost, current, k) = pq.top();
        cost = -cost;
        pq.pop();
        if(minTime[k][current]<cost){
            continue;
        }
        for(auto nextNode: map[current]){
            if(k<K){
                long long nextc = cost;
                if(cost<minTime[k+1][nextNode.first]){
                    minTime[k+1][nextNode.first] = cost;
                    pq.emplace(-cost, nextNode.first, k+1);
                }
            }
            long long nextc = cost+nextNode.second;
            if(nextc<minTime[k][nextNode.first]){
                minTime[k][nextNode.first] = nextc;
                pq.emplace(-nextc, nextNode.first, k);
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>N>>M>>K;
    map.assign(N+1, vector<pair<int, long long> >());
    minTime.assign(K+1, vector<long long>(N+1, INT64_MAX));
    for(int i = 0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        map[a].emplace_back(b, c);
        map[b].emplace_back(a, c);
    }

    dij(1);
    long long rst = minTime[0][N];
    for(int i = 0; i<=K; i++){
        rst = min(rst, minTime[i][N]);
    }
    cout<<rst;

    return 0;
}