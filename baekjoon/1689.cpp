#include <bits/stdc++.h>
using namespace std;
int st[1000005], ed[1000005], cnt = 0, max_ = -1, i, j, c, N;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>N;
    for(i=0; i<N; i++)
        cin>>st[i]>>ed[i];
    sort(st, st+N);
    sort(ed, ed+N);
    i=j=0;
    while(i<N){
        c = st[i];
        cnt++;
        while(st[++i]==c) cnt++;
        while(ed[j]<=c)j++,cnt--;
        max_ = max(max_, cnt);
    }
    cout<<max_;
    return 0;
}