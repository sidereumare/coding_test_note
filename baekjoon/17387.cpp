#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
//벡터: p1->p2, p1->p3
ll ccw(pair<ll, ll> &p1, pair<ll, ll> &p2, pair<ll, ll> &p3){
    return (p2.X-p1.X)*(p3.Y-p1.Y) - (p2.Y-p1.Y)*(p3.X-p1.X);
}
bool chk_bound(pair<ll, ll> &p1, pair<ll, ll> &p2, pair<ll, ll> &p3){
    if(p1.X==p2.X && p2.X==p3.X){
        return p3.Y<=max(p1.Y, p2.Y) && p3.Y>=min(p1.Y, p2.Y);
    }
    return p3.X<=max(p1.X, p2.X) && p3.X>=min(p1.X, p2.X);
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    vector<pair<ll, ll> > points(4);
    for(auto &p: points){
        cin>>p.first>>p.second;
    }
    if( ( (ccw(points[0], points[1], points[2]) < 0) != (ccw(points[0], points[1], points[3]) < 0) ) &&
    ( (ccw(points[2], points[3], points[0]) < 0) != (ccw(points[2], points[3], points[1]) < 0)) ){
        cout<<"1";
    }
    else if((ccw(points[0], points[1], points[2]) == 0) && chk_bound(points[0], points[1], points[2]) ) {
        cout<<"1";
    }
    else if((ccw(points[0], points[1], points[3]) == 0) && chk_bound(points[0], points[1], points[3]) ) {
        cout<<"1";
    }
    else if((ccw(points[2], points[3], points[0]) == 0) && chk_bound(points[2], points[3], points[0]) ) {
        cout<<"1";
    }
    else if((ccw(points[2], points[3], points[1]) == 0) && chk_bound(points[2], points[3], points[1]) ) {
        cout<<"1";
    }else{
        cout<<"0";
    }

    return 0;
}