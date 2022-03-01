#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int, int> > mv = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N, rst1 = 0, rst2 = 0;
vector<vector<bool> > vis;
vector<string> paper(N);
bool chkbound(pair<int, int> &pos){ return pos.X<N && pos.X>-1 && pos.Y<N && pos.Y>-1; }
bool bfs(pair<int, int> st){
    if(vis[st.Y][st.X])
        return false;
    queue<pair<int, int> > q;
    q.emplace(st);
    vis[st.Y][st.X] = true;
    char c = paper[st.Y][st.X];
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        for(auto n: mv){
            n.X += current.X;
            n.Y += current.Y;
            if(!chkbound(n) || c!=paper[n.Y][n.X] || vis[n.Y][n.X])
                continue;
            q.emplace(n);
            vis[n.Y][n.X] = true;
        }
    }
    return true;
}
int main(){
    cin>>N;
    paper.assign(N, "");
    vis.assign(N, vector<bool>(N, false));
    for(auto &s: paper)
        cin>>s;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            if(bfs({j, i}))
                rst1++;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++){
            vis[i][j] = false;
            if(paper[i][j]=='R')
                paper[i][j] = 'G';
        }
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            if(bfs({j, i}))
                rst2++;
    cout<<rst1<<' '<<rst2;
    return 0;
}