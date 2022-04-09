#include <bits/stdc++.h>

using namespace std;
int main(){
    string str;
    while(true){
        getline(cin, str);
        if(cin.eof()==true){
            break;
        }
        int a = 0, b = 0, c = 0, d = 0;
        for(char& ch: str){
            if(ch>='a' && ch<='z'){
                a++;
            }else if(ch>='A' && ch<='Z'){
                b++;
            }else if(ch==' '){
                c++;
            }else{
                d++;
            }
        }
        cout<<a<<' '<<b<<' '<<d<<' '<<c<<'\n';
    }
    return 0;
}