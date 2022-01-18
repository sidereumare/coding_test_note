#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int i = 0; i<T; i++){
        string s;
        int K;
        cin>>s>>K;
        vector<vector<int> > pos(26,vector<int>());
        for(int i = 0; i<s.length(); i++){
            pos[s[i]-'a'].push_back(i);
        }
        int maxResult = -1, minResult = INT32_MAX;
        for(auto v: pos){
            if(v.size()>=K){
                for(int j = 0; j<=v.size()-K; j++){
                    int l = v[j+K-1]-v[j]+1;
                    maxResult = max(maxResult, l);
                    minResult = min(minResult, l);
                }
            }
        }
        if(maxResult==-1){
            cout<<"-1\n";
        }else{
            cout<<minResult<<' '<<maxResult<<'\n';
        }
    }
    return 0;
}