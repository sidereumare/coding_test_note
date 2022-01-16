#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

unordered_map<string, vector<string>> dic;
unordered_set<string> visit;
int N, max = 0;

string bfs(string st){
    visit.emplace(st);
    queue<string> q;
    q.emplace(st);
    string current;
    while(!q.empty()){
        current = q.front();
        q.pop();
        for(auto next: dic[current]){
            if(visit.emplace(next).second){
                q.emplace(next);
            }
        }
    }
    return current;
}
//길이 s1+1==s2인 입력만
bool isNext(string s1, string s2){
    int j = 0;
    for(int i = 0; i<s2.size(); i++){
        if(s2[i]==s1[j]){
            j++;
        }
        if(j==s1.size()){
            return true;
        }
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string start;
    cin>>N>>start;

    //입력
    for(int i = 0; i<N; i++){
        string t;
        cin>>t;
        dic.emplace(t, vector<string>());
    }
    for(auto t1 = dic.begin(); t1!=dic.end(); t1++){
        for(auto t2 = dic.begin(); t2!=dic.end(); t2++){
            if((t1->first.size()+1) == t2->first.size() ){
                if(isNext(t1->first, t2->first)){
                    t1->second.emplace_back(t2->first);
                }
            }
        }
    }
    cout<<bfs(start);

    return 0;
}