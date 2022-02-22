#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    cin>>N>>M;
    vector<string> arr(N);
    map<string, int> dic;
    for(int i = 0; i<N; i++){
        cin>>arr[i];
        dic.emplace(arr[i], i);
    }
    for(int i = 0; i<M; i++){
        string s;
        cin>>s;
        if(s[0]>='0'&&s[0]<='9'){
            cout<<arr[stoi(s)-1]<<'\n';
        }else{
            cout<<dic[s]+1<<'\n';
        }
    }
    return 0;
}