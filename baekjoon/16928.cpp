#include <bits/stdc++.h>

using namespace std;
vector<int> dist(101, INT32_MAX), ladder(101, INT32_MAX);
queue<int> q;
int main(){
    int N, M;
    cin>>N>>M;
    for(int i = 0; i<N+M; i++){
        int a, b;
        cin>>a>>b;
        ladder[a] = b;
    }
    dist[1] = 0;
    q.emplace(1);
    while(!q.empty()){
        int current = q.front(), next;
        q.pop();
        for(int i = 1; i<=6; i++){
            next = i+current;
            next = ladder[next]!=INT32_MAX?ladder[next]:next;
            if(next<101 && dist[next]>dist[current]+1){
                dist[next] = dist[current]+1;
                q.emplace(next);
            }
        }
    }
    cout<<dist[100];
    return 0;
}