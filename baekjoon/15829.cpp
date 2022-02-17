#include <iostream>

using namespace std;
int main(){
    int L;
    string s;
    cin>>L>>s;
    long long r = 1, m = 1234567891, rst = 0;
    for(char c: s){
        rst = (rst+((c-96)*r)%m)%m;
        r = (r*31)%m;
    }
    cout<<rst;
    return 0;
}