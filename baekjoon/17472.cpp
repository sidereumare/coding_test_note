#include <bits/stdc++.h>
#define Y first
#define X second
#define INF 500000
using namespace std;
int min_dist[9][9], mx[4] = {0,0,-1,1}, my[4]={1,-1,0,0};
int n, m;
int M[105][105];
int island = 2;
bool chkbound(const pair<int, int> &p){
    return p.Y>-1&&p.Y<n&&p.X>-1&&p.X<m;
}

int prim(){
    priority_queue<pair<int, int> > pq;
    bool selected[9];
    int rst = 0;
    for(bool& s: selected){
        s = false;
    }
    pq.emplace(0, 2);
    selected[2] = 0;
    while(!pq.empty()){
        auto cur = pq.top();
        cur.first=-cur.first;
        pq.pop();
        if(selected[cur.second]){
            continue;
        }
        rst+=cur.first;
        selected[cur.second] = true;
        for(int i = 2; i<island; i++){
            if(min_dist[cur.second][i]!=INF){
                pq.emplace(-min_dist[cur.second][i], i);
            }
        }
    }

    for(int i = 2; i<island; i++){
        if(!selected[i]){
            return -1;
        }
    }
    return rst;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>M[i][j];
        }
    }
    for(int i = 0; i<9; i++)
    for(int j = 0; j<9; j++)
    min_dist[i][j] = INF;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(M[i][j]==1){
                queue<pair<int, int> > q;
                q.emplace(i, j);
                M[i][j] = island;
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int k = 0; k<4; k++){
                        auto nxt = cur;
                        nxt.X+=mx[k];
                        nxt.Y+=my[k];
                        if(chkbound(nxt) && M[nxt.Y][nxt.X]==1){
                            M[nxt.Y][nxt.X] = island;
                            q.emplace(nxt);
                        }
                    }
                }
                island++;
            }
        }
    }

    int before = 0, dist = 0;
    for(int i = 0; i<n; i++){
        before = 0;dist = 0;
        for(int j = 0; j<m; j++){
            if(M[i][j]!=0){
                if(before!=0 && dist>1){
                    min_dist[before][M[i][j]] = min(min_dist[before][M[i][j]], dist);
                    min_dist[M[i][j]][before] = min(min_dist[M[i][j]][before], dist);
                }
                before = M[i][j];
                dist = 0;
            }else if(before!=0){
                dist++;
            }
        }
        before = 0;
    }
    for(int j = 0; j<m; j++){
        before = 0; dist = 0;
        for(int i = 0; i<n; i++){
            if(M[i][j]!=0){
                if(before!=0 && dist>1){
                    min_dist[before][M[i][j]] = min(min_dist[before][M[i][j]], dist);
                    min_dist[M[i][j]][before] = min(min_dist[M[i][j]][before], dist);
                }
                before = M[i][j];
                dist = 0;
            }else if(before!=0){
                dist++;
            }
        }
    }

    cout<<prim();
    return 0;
}