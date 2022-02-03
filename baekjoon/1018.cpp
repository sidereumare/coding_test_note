#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
vector<string> arr;
int count(int i, int j, char before){
    int cnt = 0;
    for(int k = 0; k<8; k++){
        for(int l = 0; l<8; l++){
            if(arr[i+k][j+l]==before){
                cnt++;
            }
            before = before=='B'?'W':'B';
        }
        before = before=='B'?'W':'B';
    }
    return cnt;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        string s;
        cin>>s;
        arr.emplace_back(s);
    }
    int rst = 500000;
    for(int i = 0; i<=N-8; i++){
        for(int j = 0; j<=M-8; j++){
            rst = min(count(i, j, 'B'), min(count(i, j, 'W'), rst));
        }
    }
    cout<<rst;
    return 0;
}