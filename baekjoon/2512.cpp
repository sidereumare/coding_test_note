#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n, arr[10005], sum[10005], b;
    cin>>n;
    sum[0] = arr[0] = 0;
    for(int i = 1; i<=n; i++)
        cin>>arr[i];
    sort(arr, arr+n+1);
    for(int i = 1; i<=n; i++)
        sum[i] = sum[i-1]+arr[i];
    cin>>b;
    for(int i = n-1; i>-1; i--){
        if(sum[i]+(n-i)*arr[i]<=b){
            int s = arr[i], e = arr[i+1], m;
            while(s<e){
                m = (s+e)/2;
                if(sum[i]+(n-i)*m<b)
                    s = m+1;
                else
                    e = m;
            }
            m = sum[i]+(n-i)*e>b?e-1:e;
            cout<<m;
            return 0;
        }
    }
    return 0;
}