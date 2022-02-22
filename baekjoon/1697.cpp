#include <iostream>
#include <queue>
using namespace std;
int main(){
    int N, K;
    cin>>N>>K;
    queue<pair<int, int> > q;
    vector<bool> visit(210000, false);
    q.emplace(N, 0);
    if(N<K){
        while(true){
            auto current = q.front();
            visit[current.first] = true;
            if(current.first==K){
                cout<<current.second;
                break;
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
    }else{
        cout<<N-K;
    }

    return 0;
}