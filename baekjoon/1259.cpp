#include <iostream>
#include <string>
using namespace std;
bool chk(string s){
    int l = s.length()-1;
    for(int i = 0; i<=l/2; i++){
        if(s[l-i]!=s[i]){
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    while(s!="0"){
        if(chk(s)){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
        cin>>s;
    }
    return 0;
}