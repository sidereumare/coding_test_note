#include <bits/stdc++.h>
using namespace std;
struct info{
    int S, T, p;
};
int main(){
    int N, sum = 0;
    cin>>N;
    vector<bool> chk(N, true);
    vector<info> arr(N);
    for(int i = 0; i<N; i++){
        cin>>arr[i].T>>arr[i].S;
        arr[i].p = i+1;
    }
    stable_sort(arr.begin(), arr.end(), [](const info &a, const info &b)->bool{
        return ((double)a.S/(double)a.T)>((double)b.S/(double)b.T);
    });
    for(auto&c: arr){
        cout<<c.p<<' ';
    }
    return 0;
}