#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> arr(N, 0);
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int mean = 0, median, mode, rang;
    vector<int> cnt(8003, 0);
    for(int &c: arr){
        mean+=c;
        cnt[c+4000]++;
    }
    mean = floor((double)mean/(double)N+0.5);
    median = arr[N/2];
    int max = 0;
    bool flg = true;
    for(int i = 0; i<8003; i++){
        if(max<cnt[i]){
            flg = true;
            max = cnt[i];
            mode = i-4000;
        }else if(max==cnt[i]&&flg){
            flg = false;
            mode = i-4000;
        }
    }
    rang = *arr.rbegin() - *arr.begin();
    cout<<mean<<'\n'<<median<<'\n'<<mode<<'\n'<<rang;
    return 0;
}