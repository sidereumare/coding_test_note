#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){
    int N;
    queue<int> q;
    cin>>N;
    for(int i = 1; i<=N; i++){
        q.emplace(i);
    }
    bool chk = true;
    while(q.size()!=1){
        if(chk){
            q.pop();
        }else{
            q.emplace(q.front());
            q.pop();
        }
        chk=!chk;
    }
    cout<<q.front();
    return 0;
}