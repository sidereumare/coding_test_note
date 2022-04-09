#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll s, t;
    cin>>s>>t;
    if(s==t){
        cout<<0;
        return 0;
    }
    map<ll, char > before;
    queue<ll> q;
    q.emplace(s);
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        if(cur>1000000000) continue;
        if(cur==t){
            break;
        }
        auto it = before.find(cur*cur);
        if(it==before.end()){
            before.emplace(cur*cur, '*');
            q.emplace(cur*cur);
        }
        it = before.find(cur+cur);
        if(it==before.end()){
            before.emplace(cur+cur, '+');
            q.emplace(cur+cur);
        }
        it = before.find(1);
        if(it==before.end()){
            before.emplace(1, '/');
            q.emplace(1);
        }
    }
    if(before.find(t)==before.end()){
        cout<<-1;
        return 0;
    }
    ll c = t;
    vector<char> rst;
    while(c!=s){
        rst.emplace_back(before[c]);
        if(before[c]=='*'){
            c = sqrt(c);
        }else if(before[c]=='+'){
            c = c/2;
        }else{
            c = s;
        }
    }
    for(auto it = rst.rbegin(); it!=rst.rend(); it++){
        cout<<*it;
    }
    return 0;
}