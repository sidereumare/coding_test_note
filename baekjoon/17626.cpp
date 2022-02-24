#include <bits/stdc++.h>

using namespace std;
int main(){
    int N;
    vector<int> dp(50001, INT32_MAX), sq;
    dp[0] = 0;
    for(int i = 1; i<224; i++){
        sq.emplace_back(i*i);
        dp[*(sq.end()-1)] = 1;
    }
    for(int i = 1; i<=50000; i++){
        for(int &c: sq){
            if(i-c<0){
                break;
            }
            dp[i] = min(dp[i], dp[i-c]+1);
        }
    }
    cin>>N;
    cout<<dp[N];
    return 0;
}