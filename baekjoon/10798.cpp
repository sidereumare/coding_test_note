#include <bits/stdc++.h>

using namespace std;
int main(){
    vector<string> v(5);
    int m = -1;
    for(auto &c: v){
        cin>>c;
        m = max(m, (int)c.length());
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<5; j++){
            if(v[j].length()<=i) continue;
            cout<<v[j][i];
        }
    }
    return 0;
}