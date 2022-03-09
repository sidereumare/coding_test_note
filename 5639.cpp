#include <bits/stdc++.h>
using namespace std;
int tree[10005];
void postOrder(int st, int ed){
    if(st>=ed){
        return;
    }
    int root = tree[st], sp = st+1;
    while(tree[sp]<root && sp<ed){
        sp++;
    }
    postOrder(st+1, sp);
    postOrder(sp, ed);
    cout<<root<<'\n';
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n, pos = 0;
    while(cin>>n){
        tree[pos++] = n;
    }
    postOrder(0, pos);
    return 0;
}