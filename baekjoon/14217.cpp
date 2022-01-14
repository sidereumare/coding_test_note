#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

vector<int> dis;
vector<vector<int> > map;
void bfs(int start){
    dis.assign(map.size(), -1);
    if(start==1){
        dis[start] = 0;
    }
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int current = q.front();
        int dist = dis[current];
        q.pop();
        for(int i: map[current]){
            if(dis[i]>dist+1||dis[i]==-1){
                dis[i] = dist+1;
                q.push(i);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    map.assign(n+1, vector<int>());
    dis.assign(n+1, -1);
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    int q;
    cin>>q;
    for(int i = 0; i<q; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==1){
            //추가
            map[b].push_back(c);
            map[c].push_back(b);
            if(dis[b]>dis[c]){
                b = c;
            }
            bfs(1);
        }else{
            //삭제
            map[b].erase(remove(map[b].begin(), map[b].end(), c), map[b].end());
            map[c].erase(remove(map[c].begin(), map[c].end(), b), map[c].end());
            bfs(1);
        }
        for(int j = 1; j<=n; j++){
            cout<<dis[j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}