//hn = h(n-1)+4n-3, h1 = 1 (n>0인 정수)
#include <iostream>
#include <vector>
// #include <queue>
#include <climits>
using namespace std;

vector<int> hexN;
// queue<pair<int, int> > q;
int dp[1000005], rst = 0, N;
void gethex(){
    hexN.emplace_back(1);
    int before = 1, cnt = 1;
    while(before<1000005){
        before += 4*(++cnt)-3;
        hexN.emplace_back(before);
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    gethex();
    cin>>N;
    //초기화
    for(int i = 1; i<=1000000; i++){
        dp[i]=INT32_MAX;
    }
    dp[0] = 0;
    //--1
    // q.emplace(0, 0);
    // while(!q.empty()){
    //     auto cur = q.front();
    //     int next = cur.second+1;
    //     q.pop();
    //     if(dp[cur.first]<cur.second){
    //         continue;
    //     }
    //     for(int t: hexN){
    //         t = cur.first+t;
    //         if(t<=1000000){
    //             if(next<dp[t]){
    //                 dp[t] = next;
    //                 if(t==N){
    //                     cout<<next;
    //                     return 0;
    //                 }
    //                 q.emplace(t, next);
    //             }
    //         }else{
    //             break;
    //         }
    //     }
    // }

    //--2
    // for(int i = 0; i<=1000000; i++){
    //     int next = dp[i]+1;
    //     for(int t: hexN){
    //         if(i+t<=1000000){
    //             if(next<dp[i+t]){
    //                 dp[i+t] = next;
    //             }
    //         }else{
    //             break;
    //         }
    //     }
    // }

    for (int i = 0; i < hexN.size(); i++)
    {
        dp[hexN[i]] = 1;
        for (int j = i; j < hexN.size(); j++)
            if (hexN[i] + hexN[j] <= 1000000)
                dp[hexN[i] + hexN[j]] = min(dp[hexN[i] + hexN[j]], 2);
    }
    for(int cur: hexN){
        dp[cur] = 1;
        for(int i = 0; i+cur<=146858; i++){
            dp[i+cur] = min(dp[i]+1, dp[i+cur]);
        }
    }
    cout<<dp[N];
    
    return 0;
}