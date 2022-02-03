#include <iostream>

using namespace std;
int main(){
    int N, K;
    cin>>N>>K;
    long long r = 1;
    for(int i = 0; i<K; i++){
        r*=N-i;
    }
    for(int i = 1; i<=K; i++){
        r/=i;
    }
    cout<<r;
    return 0;
}