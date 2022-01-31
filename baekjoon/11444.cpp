#include <iostream>
#include <unordered_map>
#define MOD 1000000007
using namespace std;
typedef unsigned long long ull;
unordered_map<ull, ull> map;
ull solve(ull n){
    if(n<3)return 1;
    auto it = map.find(n);
    if(it!=map.end()){
        return it->second;
    }
    ull fn, fnm, rst;
    fn = solve(n/2);
    if(n%2==0){
        fnm = solve(n/2-1);
        rst = fn*((fn+2*fnm%MOD)%MOD)%MOD;
    }else{
        fnm = solve(n/2+1);
        rst = (fn*fn%MOD+fnm*fnm%MOD)%MOD;
    }
    map.emplace(n, rst);
    return rst;
}
int main(){
    // fn+1fn-1=-1^n+fn^2
    // fn+n=fn(fn-1+fn+1)=fn(fn-1+fn+fn-1)=fn(fn+2fn-1)
    // f2n+1=fn^2+fn+1^2
    ull n;
    cin>>n;
    cout<<solve(n);
    return 0;
}