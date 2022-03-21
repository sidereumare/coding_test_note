#include <bits/stdc++.h>

using namespace std;
#define INF 100000
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n, m, r;
    cin>>n>>m>>r;
    int items[101], map[101][101];
    for(int i = 1; i<=n; i++){
        cin>>items[i];
    }
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=n; j++){
            map[i][j] = i==j?0:INF;
        }
    }
    for(int i = 0; i<r; i++){
        int a, b, c;
        cin>>a>>b>>c;
        map[a][b] = c;
        map[b][a] = c;
    }

    for(int k = 0; k<=n; k++){
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=n; j++){
                int sum = map[i][k]+map[k][j];
                map[i][j] = sum<map[i][j]?sum:map[i][j];
            }
        }
    }
    int sum = 0, max_ = 0;
    for(int i = 0; i<=n; i++){
        sum = 0;
        for(int j = 0; j<=n; j++){
            if(map[i][j]<=m){
                sum+=items[j];
            }
        }
        max_ = max(sum, max_);
    }
    cout<<max_;
    return 0;
}