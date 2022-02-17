#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int test, N, t, rst;
    cin>>test;
    for(int test_case = 0; test_case<test; test_case++){
        cin>>N>>rst;
        vector<int> list;
        queue<pair<int, int> > q;
        priority_queue<int> pq;
        for(int i = 0; i<N; i++){
            cin>>t;
            q.emplace(t, i);
            pq.emplace(t);
        }
        int cnt = 1;
        while(!pq.empty()){
            if(q.front().first==pq.top()){
                if(q.front().second==rst){
                    cout<<cnt<<'\n';
                    break;
                }
                pq.pop();
                q.pop();
                cnt++;
            }else{
                q.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}