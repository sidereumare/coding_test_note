#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int N, K;
    cin>>N>>K;
    queue<pair<int, int> > q;
    vector<bool> visit(210000, false);
    int min_ = 10000000, cnt = 0;
    q.emplace(N, 0);
    while(!q.empty()){
        auto current = q.front();
        visit[current.first] = true;
        if(current.first==K){
            if(min_==current.second){
                cnt++;
            }else if(min_>current.second){
                min_ = current.second;
                cnt = 1;
            }
        }
        q.pop();
        if(current.first>100001||!visit[current.first]){
            continue;
        }

        if(0<current.first && !visit[current.first-1]){
            q.emplace(current.first-1, current.second+1);
        }
        if(current.first < K && !visit[current.first+1]){
            q.emplace(current.first+1, current.second+1);
        }
        if(current.first < K && !visit[current.first*2]){
            q.emplace(current.first*2, current.second+1);
        }
    }
    cout<<min_<<'\n'<<cnt;
    return 0;
}