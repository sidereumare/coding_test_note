#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool dp[2501][2501];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, sumAll = 0;
    vector<int> arr;
    cin>>N;
    for(int i = 0; i<N; i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }

    int a, b, c;
    a = b = c = 0;
    
    dp[0][0] = true;

    for(int i = 0; i<arr.size(); i++){
        sumAll+=arr[i];
        for(int j = sumAll; j>=0; j--){
            for(int k = sumAll; k>=0; k--){
                if(j-arr[i]>=0){
                    dp[j][k] |= dp[j-arr[i]][k];
                }
                if(k-arr[i]>=0){
                    dp[j][k] |= dp[j][k-arr[i]];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= sumAll; i++){
        for (int j = 0; j <= i; j++){
            if (dp[i][j] && j >= (sumAll - i - j)){
                ans = max(ans, sumAll - i - j);
            }
        }
    }
    cout<<ans;
    
    return 0;
}