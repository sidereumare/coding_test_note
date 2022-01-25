#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef unsigned long long ull;
vector<ull> gx;
void calcAll(){
    gx.assign(1000003, 0);
    for(int i = 1; i<=1000000; i++){
        for(int j = i; j<=1000000; j+=i){
            gx[j] += i;
        }
        gx[i] += gx[i-1];
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    calcAll();
    cin>>n;
    cout<<gx[n];
    return 0;
}