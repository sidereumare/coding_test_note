#include <bits/stdc++.h>

using namespace std;
int n, m, ice[305][305], mx[4]={1,-1,0,0}, my[4]={0,0,1,-1};
bool chkbound(int x, int y){
    return x<m && x>-1 && y<n && y>-1;
}
int vis[305][305];
bool bfs(){
    memset(vis, 0, sizeof(int)*305*305);
    int si=-1, sj=-1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(ice[i][j]!=0){
                si = i; sj = j;
            }
        }
        if(si!=-1){
            break;
        }
    }

    queue<pair<int, int> > q;
    q.emplace(si, sj);
    while(!q.empty()){
        auto c = q.front();
        q.pop();
        if(vis[c.first][c.second]!=0){
            continue;
        }
        vis[c.first][c.second] = 1;
        for(int i = 0; i<4; i++){
            if(chkbound(c.second+mx[i],c.first+my[i]) && ice[c.first+my[i]][c.second+mx[i]]!=0){
                q.emplace(c.first+my[i], c.second+mx[i]);
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(ice[i][j]!=0 && vis[i][j]==0){
                return true;
            }
        }
    }
    return false;
}
bool isend(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(ice[i][j]!=0)
                return false;
        }
    }
    return true;
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>ice[i][j];
        }
    }
    int cnt = 1;
    while(true){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(ice[i][j]==0 && vis[i][j]==0){
                    for(int k = 0; k<4; k++){
                        int ni = i+mx[k], nj = j+my[k];
                        if(chkbound(nj, ni)&&ice[ni][nj]!=0){
                            ice[ni][nj]--;
                            if(ice[ni][nj]==0){
                                vis[ni][nj]=1;
                            }
                        }
                    }
                }
            }
        }
        if(isend()){
            break;
        }
        if(bfs()){
            cout<<cnt;
            return 0;
        }
        cnt++;
    }
    cout<<0;
    return 0;
}