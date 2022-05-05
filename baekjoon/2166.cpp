#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<double, double> Point;
int main(){
    vector<Point> parr;
    int n;
    double d = 0;
    cin>>n;
    for(int i = 0; i<n; i++){
        int a, b;
        cin>>a>>b;
        parr.emplace_back(a, b);
    }
    for(int i = 1; i<parr.size()-1; i++){
        d+=(parr[i].X-parr[0].X)*(parr[i+1].Y-parr[0].Y)-(parr[i+1].X-parr[0].X)*(parr[i].Y-parr[0].Y);
    }
    cout.precision(1);
    cout<<fixed<<abs(d/(double)2.0);
    return 0;
}