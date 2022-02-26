#include <bits/stdc++.h>
using namespace std;
//x, y순서
vector<vector<pair<int, int> > > tet = {{{0,0}, {1, 0}, {2, 0}, {3, 0}}, 
                                        {{0,0}, {1, 0}, {0, 1}, {1, 1}},
                                        {{0,0}, {0, 1}, {0, 2}, {1, 2}},
                                        {{0,0}, {0, 1}, {1, 1}, {1, 2}},
                                        {{0,0}, {1, 0}, {2, 0}, {1, 1}}};
int N, M;
void rotref(){
    //90도 3번
    for(int i = 0; i<5; i++){
        auto c = tet[i];
        for(int i = 0; i<3; i++){
            for(auto &p: c){
                auto copy = p;
                p.first = -copy.second;
                p.second = copy.first;
            }
            tet.emplace_back(c);
        }
    }
    //y축 x축
    for(int i = 0; i<20; i++){
        auto c = tet[i];
        for(auto &p: c){
            p.second = -p.second;
        }
        tet.emplace_back(c);
        for(auto &p: c){
            p.second = -p.second;
            p.first = -p.first;
        }
        tet.emplace_back(c);
    }
}
bool chkbound(pair<int, int>& p){
    if(p.first<0||p.first>=M||p.second<0||p.second>=N){
        return false;
    }
    return true;
}
int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    rotref();
    int paper[501][501], rst = -1;
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>paper[i][j];
        }
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            for(auto& c: tet){
                int sum = 0;
                for(auto& p: c){
                    pair<int, int> next = {p.first+j, p.second+i};
                    if(chkbound(next)){
                        sum+=paper[next.second][next.first];
                    }else{
                        sum = -1;
                        break;
                    }
                }
                rst = max(rst, sum);
            }
        }
    }
    cout<<rst;
    return 0;
}