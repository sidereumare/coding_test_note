#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

int V, E;
vector<vector<pair<int, int> > > map;
void dijkstra(int start, vector<long long> &dis){
    priority_queue<pair<long long, int> > pq;
    pq.emplace(0, start);
    dis[start] = 0;
    while(!pq.empty()){
        int current = pq.top().second;
        long long cost = -pq.top().first;
        pq.pop();
        if(cost>dis[current]){
            continue;
        }
        for(auto nextNode : map[current]){
            long long nextc = nextNode.second + cost;
            if(dis[nextNode.first]>nextc){
                dis[nextNode.first] = nextc;
                pq.emplace(-nextc, nextNode.first);
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    //길 입력
    cin>>V>>E;
    map.assign(V+1, vector<pair<int, int> >());
    for(int i = 0; i<E; i++){
        int a, b, c;
        cin>>a>>b>>c;
        map[a].emplace_back(b, c);
        map[b].emplace_back(a, c);
    }
    int route[10];
    for(int i = 0; i<10; i++){
        cin>>route[i];
    }
    //아줌마 경로
    long long routec[10], beforec = 0, before;
    routec[0] = 0;
    before = route[0];
    for(int i = 1; i<10; i++){
        routec[i] = INT64_MAX;
        vector<long long> dist(V+1, INT64_MAX);
        dijkstra(before, dist);
        if(dist[route[i]]!=INT64_MAX){
            routec[i] = dist[route[i]]+beforec;
            beforec = routec[i];
            before = route[i];
        }
    }
    //출발
    int start;
    cin>>start;
    vector<long long> dis(V+1, INT64_MAX);
    dijkstra(start, dis);

    int rst = INT32_MAX;
    for(int i = 0; i<10; i++){
        if(routec[i]>=dis[route[i]] && routec[i]<INT64_MAX && route[i]<rst){
            rst = route[i];
        }
    }
    if(rst==INT32_MAX){
        cout<<-1;
    }else{
        cout<<rst;
    }
    return 0;
}