#include <bits/stdc++.h>
using namespace std;
int N, M, rst = 0, l = 0;
int calc(int cnt){ return (l<3)||(l-1)/2-N+1<0?0:(l-1)/2-N+1; }
int main(){
    string s;
    cin>>N>>M>>s;
    for(char &c : s){
        if(l%2==1){
            if(c=='O'){
                l++;
            }else{
                rst+=calc(l);
                l = 1;
            }
        }else{
            if(c=='I'){
                l++;
            }else{
                rst+=calc(l);
                l = 0;
            }
        }
    }
    rst+=calc(l);
    cout<<rst;
    return 0;
}