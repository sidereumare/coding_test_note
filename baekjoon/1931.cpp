#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<pair<int, int> > conf(N);
    for(int i = 0; i<N; i++){
        cin>>conf[i].first>>conf[i].second;
    }
    sort(conf.begin(), conf.end(), [](pair<int, int> &a, pair<int, int> &b){
        if(a.second==b.second){
            return a.first<b.first;
        }else{
            return a.second<b.second;
        }
    });
    int rst = 0, end = 0;
    for(auto &c: conf){
        if(end<=c.first){
            end = c.second;
            rst++;
        }
    }
    cout<<rst;
    return 0;
}