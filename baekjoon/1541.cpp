#include <bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin>>s;
    s+='+';
    string num = "";
    char before = '+';
    int n, sum = 0, sum1 = 0;
    for(char &c : s){
        if(c>='0'&&c<='9'){
            num+=c;
        }else{
            n = stoi(num);
            num = "";
            if(c=='+' && before=='+'){
                sum+=n;
            }else if(c=='+' && before=='-'){
                sum1-=n;
            }else if(c=='-' && before=='+'){
                sum+=n;
                before = '-';
            }else{
                sum+=sum1-n;
                sum1 = 0;
                before = '-';
            }
        }
    }
    sum+=sum1;
    cout<<sum;
    return 0;
}