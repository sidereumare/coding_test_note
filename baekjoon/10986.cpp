#include <iostream>
#include <vector>
using namespace std;
//예제
//1 0 0 1 0
//0:3 1:2   3, 3, 1
typedef long long ll;
int main(){
    ll N, M, t, rst, sum = 0;
    cin>>N>>M;
    vector<ll> arr(M+1, 0);
    for(int i = 0; i<N; i++){
        cin>>t;
        sum = (sum+t)%M;
        arr[sum]++;
    }
    rst=arr[0];
    for(ll c: arr)
        if(c>1)
            rst+=c*(c-1)/2;
    cout<<rst;
    return 0;
}