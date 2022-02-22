#include <iostream>
#include <stack>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int k, rst = 0;
    stack<int> st;
    cin>>k;
    for(int i = 0; i<k; i++){
        int c;
        cin>>c;
        if(c==0){
            st.pop();
        }else{
            st.emplace(c);
        }
    }
    while(!st.empty()){
        rst+=st.top();
        st.pop();
    }
    cout<<rst;
    return 0;
}