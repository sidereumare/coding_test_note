#include <bits/stdc++.h>

using namespace std;
string toBinary(int n)
{
    if(n==0){
        return "0";
    }
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    reverse(r.begin(), r.end());
    return r;
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i = 0; i<=n; i++){
        cout<<toBinary(i);
    }
    return 0;
}

