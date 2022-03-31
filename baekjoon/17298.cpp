#include <bits/stdc++.h>

using namespace std;
int arr[1000005], rst[1000005];
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int N;
    cin>>N;
    for(int i  = 0; i<N; i++){
        cin>>arr[i];
    }
    stack<int> st;
    for(int i = N-1; i>=0; i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            rst[i] = -1;
        }else{
            rst[i] = st.top();
        }
        st.emplace(arr[i]);
    }
    for(int i = 0; i<N; i++){
        cout<<rst[i]<<' ';
    }
    return 0;
}