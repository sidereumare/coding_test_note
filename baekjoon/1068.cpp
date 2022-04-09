
// int p[51], n, d, r;
// vector<vector<int> > c(51, vector<int>());
// void del(){
//     int pos;
//     for(int i = 0; i<c[p[d]].size(); i++){
//         if(c[p[d]][i]==d){
//             pos = i;
//             break;
//         }
//     }
//     c[p[d]].erase(c[p[d]].begin()+pos);
// }
// int cnt_t(int cur){
//     if(c[cur].size()==0){
//         return 1;
//     }
//     int cnt = 0;
//     for(auto& e: c[cur]){
//         cnt+=cnt_t(e);
//     }
//     return cnt;
// }
// int main(){
//     cin>>n;
//     for(int i= 0; i<n; i++){
//         cin>>p[i];
//         if(p[i]==-1){
//             r = i;
//             continue;
//         }
//         c[p[i]].emplace_back(i);
//     }
//     cin>>d;
//     if(d==r){
//         cout<<0;
//         return 0;
//     }
//     del();
//     cout<<cnt_t(r);
//     return 0;
// }

#include <iostream>
using namespace std;int p[51],n,d,r,z[51],a,i,j;bool k(int c){while(p[c]!=-1)c=p[c];return c==r?1:0;}int main(){cin>>n;for(;i<n;i++){cin>>p[i];if(p[i]==-1){r=i;continue;}z[p[i]]++;}cin>>d;z[p[d]]--;p[d]=-1;for(;j<n;j++)if(z[j]==0&&k(j))a++;a=r==d?0:a;cout<<a;}