#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin>>N>>K;
    deque<pair<int, int> > q;
    vector<bool> visit(210000, false);
    q.emplace_front(N, 0);
    if(N<K){
        while(true){
            auto current = q.front();
            visit[current.first] = true;
            if(current.first==K){
                cout<<current.second;
                break;
            }
            q.pop_front();
            if(current.first>100001||!visit[current.first]){
                continue;
            }
            if(0<current.first && !visit[current.first-1]){
                q.emplace_back(current.first-1, current.second+1);
            }
            if(current.first < K && !visit[current.first+1]){
                q.emplace_back(current.first+1, current.second+1);
            }
            if(current.first < K && !visit[current.first*2]){
                q.emplace_front(current.first*2, current.second);
            }
        }
    }else{
        cout<<N-K;
    }
    return 0;
}