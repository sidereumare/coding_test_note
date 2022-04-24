#include <bits/stdc++.h>
int n,m;using namespace std;int q(int t, int d){return t<d?0:t/d+q(t/d,d);}int main(){cin>>n>>m;cout<<min(q(n,2)-q(m,2)-q(n-m,2),q(n,5)-q(m,5)-q(n-m,5));return 0;}