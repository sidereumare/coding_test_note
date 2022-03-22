#include <bits/stdc++.h>

using namespace std;
int N, M, v[101], c[101], dp[10200];
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        cin>>v[i];
    }
    for(int i = 0; i<N; i++){
        cin>>c[i];
    }

    for(int i = 0; i<N; i++){
        for(int j = 10199; j>=c[i]; j--){
            if(j-c[i]>=0){
                dp[j] = max(dp[j], dp[j-c[i]]+v[i]);
            }
        }
    }

	for(int i=0; i<10200; i++) {
		if(dp[i]>=M) {
            cout<<i;
			break;
		}
	}
    return 0;
}