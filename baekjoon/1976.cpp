#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int info[203][203], root[203], N, M;
int find(int x){
    if(root[x]==x){
        return x;
    }else{
        root[x] = find(root[x]);
        return root[x];
    }
}
void uni(int x, int y){
    x = find(x);
    y = find(y);
    root[y] = x;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 0; i<203; i++){
        root[i] = i;
    }

    cin>>N;
    cin>>M;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            int t;
            cin>>t;
            if(t==1){
                uni(i, j);
            }
        }
    }
    int before, next;
    cin>>next;
    for(int i = 0; i<M-1; i++){
        before = next;
        cin>>next;
        if(find(before)!=find(next)){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}