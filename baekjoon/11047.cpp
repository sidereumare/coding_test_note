#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, K, rst = 0;
    cin>>N>>K;
    vector<int> coin(N, 0);
    for(int &c: coin){
        cin>>c;
    }
    auto bound = lower_bound(coin.begin(), coin.end(), K);
    if(bound==coin.end()){ bound--; }
    while(bound!=coin.begin()){
        rst+=K/(*bound);
        K %= *bound;
        bound--;
    }
    rst+=K;
    cout<<rst;
    return 0;
}