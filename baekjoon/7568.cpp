#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    vector<pair<int, int> > v;
    cin>>N;
    for(int i = 0; i<N; i++){
        int x, y;
        cin>>x>>y;
        v.emplace_back(x, y);
    }
    for(int i = 0; i<N; i++){
        int cnt = 1;
        for(int j = 0; j<N; j++){
            if(v[i].first<v[j].first && v[i].second<v[j].second){
                cnt++;
            }
        }
        cout<<cnt<<' ';
    }
    return 0;
}