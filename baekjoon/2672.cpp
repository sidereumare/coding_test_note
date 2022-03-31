#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct side{
    ll x, y1, y2;
    bool isleft;
    bool operator < (side& t){
        if(x == t.x){
            return isleft < t.isleft;
        }else{
            return x < t.x;
        }
    }
};
int A[20001];
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    ll N, sum = 0;
    cin>>N;
    vector<side> sides;
    for(int i = 0; i<N; i++){
        double x, y, w, h;
        cin>>x>>y>>w>>h;
        side s;
        s.x = x*10;
        s.y1 = y*10;
        s.y2 = s.y1+h*10;
        s.isleft = true;
        sides.emplace_back(s);
        s.x += w*10;
        s.isleft = false;
        sides.emplace_back(s);
    }
    sort(sides.begin(), sides.end());
    int lx = 0;
    for(side& s: sides){
        int cnt = 0;
        for(int i = 0; i<20005; i++){
            if(A[i]>0) cnt++;
        }
        sum+=cnt*(s.x-lx);
        for(int i = s.y1+1; i<=s.y2; i++){
            if(s.isleft==true) A[i]++;
            else A[i]--;
        }
        lx = s.x;
    }
    if(sum%100==0){
        cout<<sum/100;
    }else{
        cout<<fixed;
        cout.precision(2);
        cout<<(double)sum/(double)100;
    }
    return 0;
}