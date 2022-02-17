#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, t, next = 1;
    vector<char> rst;
    rst.reserve(10000);
    cin>>n;
    stack<int> st;
    for(int i = 0; i<n; i++){
        cin>>t;
        while(st.empty() || st.top()!=t){
            if(next>n){
                cout<<"NO";
                return 0;
            }
            st.emplace(next++);
            rst.emplace_back('+');
        }
        st.pop();
        rst.emplace_back('-');
    }
    for(char c: rst){
        cout<<c<<'\n';
    }
    return 0;
}