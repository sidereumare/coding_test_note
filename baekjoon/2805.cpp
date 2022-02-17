#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
vector<ll> arr, sum;
ll n, m;
ll calc(ll h){
    auto it = lower_bound(arr.begin(), arr.end(), h);
    int idx = it-arr.begin();
    return sum[idx]-(n-idx)*h;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    arr.assign(n, 0);
    sum.assign(n, 0);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    sum[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--){
        sum[i] = sum[i+1]+arr[i];
    }
    int l = 0, r = arr[n-1];
    int mid;
    while(l+1<r){
        mid = (l+r)/2;
        ll tree = calc(mid);
        if(tree>=m){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout<<l;
    return 0;
}