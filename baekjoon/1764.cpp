#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    unordered_set<string> heard, seen;
    vector<string> rst;
    int N, M;
    cin>>N>>M;
    for(int i = 0; i<N;i++){
        string s;
        cin>>s;
        heard.emplace(s);
    }
    for(int i = 0; i<M;i++){
        string s;
        cin>>s;
        seen.emplace(s);
    }
    for(string s: heard){
        if(seen.find(s)!=seen.end()){
            rst.emplace_back(s);
        }
    }
    cout<<rst.size()<<'\n';
    sort(rst.begin(), rst.end());
    for(string s: rst){
        cout<<s<<'\n';
    }
    return 0;
}