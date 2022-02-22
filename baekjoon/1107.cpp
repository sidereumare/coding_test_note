#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    vector<bool> broken(10, true);
    cin>>N>>M;
    for(int i = 0; i<M; i++){
        int t;
        cin>>t;
        broken[t] = false;
    }
    
    string s = to_string(N), s1, s2;
    for(int i = 1; i<s.length(); i++){
        int current = s[i]-'0';
        while(!broken[current] && current!=-1){
            current--;
        }
        s1.push_back()
        if(broken[current]){
            s1.emplace_back(current+'0');
            s2.emplace_back(current+'0');
        }
    }
    return 0;
}