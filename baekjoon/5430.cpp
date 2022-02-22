#include <bits/stdc++.h>

using namespace std;
deque<int>* split(string &s){
    istringstream iss(s);
    string buffer;
    deque<int> *rst = new deque<int>();
    while(getline(iss, buffer, ',')){
        rst->emplace_back(stoi(buffer));
    }
    return rst;
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false); cout.tie(NULL);
    int T;
    cin>>T;
    for(int test = 0; test<T; test++){
        string op, nums;
        int N;
        cin>>op>>N>>nums;
        nums = nums.substr(1, nums.length()-2);
        bool isr = false, e = false;
        auto num = split(nums);
        for(char &c: op){
            if(c=='D'){
                if(num->empty()){
                    e = true;
                    cout<<"error\n";
                    break;
                }
                if(isr){
                    num->pop_back();
                }else{
                    num->pop_front();
                }
            }else{
                isr = isr?false:true;
            }
        }
        if(e){
            continue;
        }
        if(num->empty()){
            cout<<"[]\n";
        }else{
            cout<<'[';
            if(isr){
                for(auto it = num->rbegin(); it!=num->rend()-1; it++){
                    cout<<*it<<',';
                }
                cout<<num->front()<<"]\n";
            }else{
                for(auto it = num->begin(); it!=num->end()-1; it++){
                    cout<<*it<<',';
                }
                cout<<num->back()<<"]\n";
            }
        }
    }
    return 0;
}