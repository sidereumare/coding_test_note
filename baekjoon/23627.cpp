#include <bits/stdc++.h>

using namespace std;
int main(){
    string s, d = "driip";
    cin>>s;
    auto sit = s.rbegin(), dit = d.rbegin();
    for(int i = 0; i<5; i++){
        if(*(sit+i)!=*(dit+i)){
            cout<<"not cute";
            return 0;
        }
    }
    cout<<"cute";
    return 0;
}