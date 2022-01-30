// (A^B)modC
// =(A*A*...*A)modC
// =(AmodC*AmodC*...*AmodC)modC
#include <iostream>
#include <unordered_map>
using namespace std;
typedef unsigned long long ull;
ull solve(int a, int b, ull c){
    if(b==1){
        return a%c;
    }
    ull rst = solve(a, b/2, c);
    rst = rst*rst%c;
    if(b%2==1){
        rst=(a*rst)%c;
    }
    return rst;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b, c;
    cin>>a>>b>>c;
    cout<<solve(a, b, c);
    return 0;
}