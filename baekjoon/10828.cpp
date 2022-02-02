#include <iostream>
#include <stack>

using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    stack<int> st;
    string inst;
    int t, N;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>inst;
        if(inst=="push"){
            cin>>t;
            st.emplace(t);
        }else if(inst=="pop"){
            if(st.empty()){
                cout<<"-1\n";
            }else{
                cout<<st.top()<<'\n';
                st.pop();
            }
        }else if(inst=="size"){
            cout<<st.size()<<'\n';
        }else if(inst=="empty"){
            if(st.empty()){
                cout<<"1\n";
            }else{
                cout<<"0\n";
            }
        }else if(inst=="top"){
            if(st.empty()){
                cout<<"-1\n";
            }else{
                cout<<st.top()<<'\n';
            }
        }
    }
    return 0;
}