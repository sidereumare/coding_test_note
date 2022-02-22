#include <iostream>
#include <vector>
using namespace std;

int rst = 0;
int N, M;
vector<bool> visit;
vector<vector<int> > V;
bool dfs(int s){
    if(visit[s]){
        return false;
    }else{
        visit[s] = true;
        for(int &c: V[s]){
            dfs(c);
        }
        return true;
    }
}
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N>>M;
    visit.assign(N, false);
    V.assign(N, vector<int>());
    for(int i = 0; i<M; i++){
        int a, b;
        cin>>a>>b;
        V[a-1].emplace_back(b-1);
        V[b-1].emplace_back(a-1);
    }
    for(int i = 0; i<N; i++){
        if(dfs(i)){
            rst++;
        }
    }
    cout<<rst;
    return 0;
}