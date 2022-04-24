#include <bits/stdc++.h>

using namespace std;
int arr[500005], rst[500005];
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    priority_queue<pair<int, int> > pq;
    for(int i = n-1; i>-1; i--){
        while(!pq.empty() && arr[i]>=-pq.top().first){
            rst[pq.top().second] = i+1;
            pq.pop();
        }
        pq.emplace(-arr[i], i);
    }
    while(!pq.empty()){
        rst[pq.top().second] = 0;
        pq.pop();
    }
    for(int i = 0; i<n; i++){
        cout<<rst[i]<<' ';
    }
    return 0;
}