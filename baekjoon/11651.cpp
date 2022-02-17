#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<pair<int, int> > arr(N, make_pair(0, 0));
    for(int i = 0; i<N; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b)->bool{
        if(a.second!=b.second){
            return a.second<b.second;
        }else{
            return a.first<b.first;
        }
    });
    for(auto &c: arr){
        cout<<c.first<<" "<<c.second<<'\n';
    }
    return 0;
}