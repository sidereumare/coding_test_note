#include <iostream>
#include <set>
#include <cmath>
using namespace std;
bool chk(int n){
    while(n>500){
        if(n%1000==666){
            return true;
        }else{
            n/=10;
        }
    }
    return false;
}
int main(){
    set<int> s;
    long long arr[10005];
    int d = 666;
    int cnt = 1;
    for(int i = 666; i<100000000; i++){
        if(chk(i)){
            arr[cnt++] = i;
        }
        if(cnt==10001){
            break;
        }
    }
    int n;
    cin>>n;
    cout<<arr[n];
    return 0;
}