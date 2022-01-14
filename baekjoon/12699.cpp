#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int N, cnt[3] = {0,0,0}, place[3] = {0,0,0}, cnt_[3], place_[3];
string A, B;
string rst;

void cp(){
    for(int i = 0; i<3; i++){
        place_[i] = place[i];
        cnt_[i] = cnt[i];
    }
}
bool chkch(int i, int j){
    if((B[i]-'a') == j || cnt[j] == -1) return false;
    for(int k = 0; k<=min(cnt[0], place[1]); k++){
        cp();
        cnt_[0]-=k;
        place_[1]-=k;
        if(place_[2] < cnt_[0]) continue;
        place_[2] -= cnt_[0];
        cnt_[1] -= min(place_[2], cnt_[1]);
        if(place_[0] < cnt_[1]) continue;
        place_[0] -= cnt_[1];
        if(place_[0] + place_[1] < cnt_[2]) continue;
        return true;
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N;
    cin>>A>>B;
    for(int i = 0; i<N; i++){
        cnt[A[i]-'a']++;
        place[B[i]-'a']++;
    }
    for(int i = 0; i<N; i++){
        place[B[i]-'a']--;
        for(int j = 0; j<3; j++){
            cnt[j]--;
            if(chkch(i,j)){
                rst.push_back('a'+j);
                break;
            }
            cnt[j]++;
        }
    }
    cout<<rst;
    return 0;
}