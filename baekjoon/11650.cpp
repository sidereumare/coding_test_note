#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<pair<int, int> > arr(N, make_pair(0, 0));
    for(int i = 0; i<N; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(), arr.end());
    for(auto &c: arr){
        cout<<c.first<<" "<<c.second<<'\n';
    }
    return 0;
}