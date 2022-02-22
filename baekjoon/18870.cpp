#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> arr(N), index;
    index.reserve(N);
    set<int> arr1;
    for(int i = 0; i<N; i++){
        cin>>arr[i];
        arr1.emplace(arr[i]);
    }
    for(int c: arr1){
        index.emplace_back(c);
    }
    sort(index.begin(), index.end());
    for(int &c: arr){
        cout<<lower_bound(index.begin(), index.end(), c)-index.begin()<<' ';
    }
    return 0;
}