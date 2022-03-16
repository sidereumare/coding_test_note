#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<vector<int> > mMul(vector<vector<int> > &mA, vector<vector<int> > &mB, int mod){
    int n = mA.size();
    vector<vector<int> > rst(n, vector<int>(n, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                rst[i][j] += mA[i][k]*mB[k][j]%mod;
                rst[i][j] %= mod;
            }
        }
    }
    return rst;
}

vector<vector<int> > powerMat(vector<vector<int> > &mat, ll B, int mod){
    int n = mat.size();
    if(B==1){
        return mat;
    }
    auto h = powerMat(mat, B/2, mod);
    h = mMul(h, h, mod);
    if(B%2==1){
        return mMul(mat, h, mod);
    }else{
        return h;
    }
}

int main(){
    int N;
    ll M;
    cin>>N>>M;
    vector<vector<int> > m(N, vector<int>(N));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>m[i][j];
            if(m[i][j]==1000){
                m[i][j] = 0;
            }
        }
    }
    auto rst = powerMat(m, M, 1000);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout<<rst[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}