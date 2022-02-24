#include <bits/stdc++.h>

using namespace std;
void div(int n, int d, int &r){
    while(n%d==0){
        r++;
        n/=d;
    }
}
int main(){
    int N, d2 = 0, d5 = 0;
    cin>>N;
    for(int i = 1; i<=N; i++){
        div(i, 2, d2);
        div(i, 5, d5);
    }
    cout<<min(d2, d5);
    return 0;
}