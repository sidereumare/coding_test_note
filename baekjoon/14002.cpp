#include <bits/stdc++.h>

using namespace std;
int N, dp[1000005], arr[1000005], before[1000005];
vector<pair<int, int> > lis;
int main(){
    cin>>N;
    lis.reserve(N+5);
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
    lis.emplace_back(arr[0], 0);
    dp[0] = 1;
    before[0] = -1;
    int max_ = 1, rst = 0;;
    for(int i = 1; i<N; i++){
        pair<int, int> cur(arr[i], i);
        auto it = upper_bound(lis.begin(), lis.end(), cur, 
        [](const pair<int, int> &a, const pair<int, int> &b)->bool{
            return a.first<b.first;
        });
        if((it-1)->first == cur.first){
            continue;
        }
        if(it==lis.end()){
            lis.emplace_back(cur);
        }else{
            it->first = arr[i];
            it->second = i;
        }
        dp[i] = it-lis.begin()+1;
        if(dp[i]>max_){
            max_ = dp[i];
            rst = i;
        }

        if(it==lis.begin()){
            before[i] = -1;
        }else{
            before[i] = (it-1)->second;
        }
    }
    vector<int> rst_;
    rst_.reserve(1000005);
    while(rst!=-1){
        rst_.emplace_back(arr[rst]);
        rst = before[rst];
    }
    reverse(rst_.begin(), rst_.end());
    cout<<max_<<'\n';
    for(auto& c: rst_){
        cout<<c<<' ';
    }
    return 0;
}
