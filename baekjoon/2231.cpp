#include <iostream>

using namespace std;
int partialSum(int t){
    int rst = t;
    while(t>0){
        rst += t%10;
        t/=10;
    }
    return rst;
}
int main(){
    int N;
    cin>>N;
    for(int i = 1; i<1000001; i++){
        int p = partialSum(i);
        if(p==N){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
    return 0;
}