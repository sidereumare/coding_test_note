#include <iostream>

using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    unsigned int N;
    cin>>N;
    while((N&1)!=1){
        N>>=1;
    }
    N=(N==1?1:0);
    cout<<N;
    return 0;
}