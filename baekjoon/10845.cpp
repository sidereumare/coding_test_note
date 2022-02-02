#include <iostream>
#include <deque>

using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    deque<int> deq;
    string inst;
    int t, N;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>inst;
        if(inst=="push_front"){
            cin>>t;
            deq.emplace_front(t);
        }else if(inst=="pop_front"){
            if(deq.empty()){
                cout<<"-1\n";
            }else{
                cout<<deq.front()<<'\n';
                deq.pop_front();
            }
        }else if(inst=="push_back"){
            cin>>t;
            deq.emplace_back(t);
        }else if(inst=="pop_back"){
            if(deq.empty()){
                cout<<"-1\n";
            }else{
                cout<<deq.back()<<'\n';
                deq.pop_back();
            }
        }else if(inst=="size"){
            cout<<deq.size()<<'\n';
        }else if(inst=="empty"){
            if(deq.empty()){
                cout<<"1\n";
            }else{
                cout<<"0\n";
            }
        }else if(inst=="front"){
            if(deq.empty()){
                cout<<"-1\n";
            }else{
                cout<<deq.front()<<'\n';
            }
        }else if(inst=="back"){
            if(deq.empty()){
                cout<<"-1\n";
            }else{
                cout<<deq.back()<<'\n';
            }
        }
    }
    return 0;
}