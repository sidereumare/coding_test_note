#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
int N, K, R;
set<pair<pair<int, int>, pair<int, int> > > road;
vector<vector<bool> > map, visit;
vector<pair<int, int> > mv({{0,1}, {0,-1}, {1,0}, {-1,0}});

bool chk_boundary(pair<int, int> n){
    if(n.first>0 && n.first<=N && n.second>0 && n.second<=N){
        return true;
    }else{
        return false;
    }
}
int search(pair<int, int> start){
    if(!map[start.first][start.second]){
        return 0;
    }
    int rst = 1;
    queue<pair<int, int> > q;
    q.push(start);
    visit[start.first][start.second] = true;
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        for(auto m: mv){
            auto next = make_pair(current.first+m.first, current.second+m.second);
            if(chk_boundary(next) &&
            road.find(make_pair(current>next?next:current, current>next?current:next))==road.end() &&
            !visit[next.first][next.second]){
                if(map[next.first][next.second]){
                    rst++;
                }
                visit[next.first][next.second] = true;
                q.push(next);
            }
        }
    }
    return rst;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>N>>K>>R;
    for(int i = 0; i<R; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        auto p1 = make_pair(a, b);
        auto p2 = make_pair(c, d);
        if(p1>p2){
            swap(p1, p2);
        }
        road.emplace(p1, p2);
    }

    vector<pair<int, int> > listc;
    map.assign(N+2, vector<bool>(N+2, false));
    visit.assign(N+2, vector<bool>(N+2, false));
    for(int i = 0; i<K; i++){
        int a, b;
        cin>>a>>b;
        listc.emplace_back(a, b);
        map[a][b] = true;
    }

    vector<int> rst_s;    
    for(auto c: listc){
        if(!visit[c.first][c.second]){
            int t = search(c);
            if(t!=0){
                rst_s.push_back(t);
            }
        }
    }
    int rst = 0;
    for(int i = 0; i<rst_s.size(); i++){
        for(int j = i+1; j<rst_s.size(); j++){
            rst+=rst_s[i]*rst_s[j];
        }
    }
    cout<<rst;
    return 0;
}