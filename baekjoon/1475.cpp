#include <iostream>

using namespace std;
int n[10];
int main(){
    string s;
    cin>>s;
    for(char c: s){
        n[c-'0']++;
    }
    int rst=0;
    n[6] = (n[6]+n[9])/2+((n[6]+n[9])%2==0?0:1);
    for(int i = 0; i<9; i++){
        rst = max(rst, n[i]);
    }
    cout<<rst;
    return 0;
}