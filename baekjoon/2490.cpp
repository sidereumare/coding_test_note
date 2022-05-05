#include <bits/stdc++.h>
using namespace std;
int main(){
    for(int i =0; i<3; i++){
        int cnt = 0; 
        for(int j = 0; j<4; j++){
            int a;
            cin>>a;
            if(a==0)
                cnt++;
        }
        if(cnt==0){
            cout<<"E\n";
        }else{
            cout<<(char)('A'+cnt-1)<<'\n';
        }
    }
    return 0;
}