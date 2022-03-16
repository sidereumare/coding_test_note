#include <bits/stdc++.h>

using namespace std;
int main(){
    long long A, B, rst = -1;
    cin>>A>>B;
    queue<pair<long long, int> > q;
    q.emplace(A, 0);
    while(!q.empty()){
        long long c = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(c>B){
            continue;
        }
        else if(c==B){
            rst = cnt+1;
            break;
        }
        q.emplace(c*10+1, cnt+1);
        q.emplace(c<<1, cnt+1);
    }
    cout<<rst;
    return 0;
}