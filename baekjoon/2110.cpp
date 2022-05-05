#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n, c;
    vector<int> home;
    cin>>n>>c;
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        home.emplace_back(a);
    }
    sort(home.begin(), home.end());
    int l = 1, h = *(home.end()-1)+1, m;
    while(l+1<h){
        m = (l+h)/2;
        if([c, m, &home=as_const(home)]()->bool{
            int count = 1, p = 0;
            for(int i = 1; i<home.size(); i++){
                if(home[i]-home[p]>=m){
                    count++;
                    p = i;
                }
            }
            return count>=c;
        }()){
            l = m;
        }else{
            h = m;
        }
    }
    cout<<l;
    return 0;
}