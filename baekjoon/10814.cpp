#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<pair<int, string> > mem(N, {0, ""});
    for(int i = 0; i<N; i++){
        cin>>mem[i].first>>mem[i].second;
    }
    stable_sort(mem.begin(), mem.end(), 
        [](const pair<int, string> &a, const pair<int, string> &b)->bool{
            return a.first<b.first;
        });
    for(auto &t: mem){
        cout<<t.first<<" "<<t.second<<'\n';
    }
    return 0;
}