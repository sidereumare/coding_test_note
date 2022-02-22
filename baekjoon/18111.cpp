#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, B, sum = 0, cnt, rst = 257, time = INT32_MAX;
    cin>>N>>M>>B;
    cnt = M*N;
    vector<int> arr(cnt, 0);
    for(int i = 0; i<cnt; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int i = 256; i>=0; i--){
        if(cnt*i <= B+sum){
            int current = 0;
            for(int &c: arr){
                if(c>i){
                    current += 2*(c-i);
                }else{
                    current += i-c;
                }
            }
            if(current<time){
                time = current;
                rst = i;
            }
        }
    }
    cout<<time<<' '<<rst;
    return 0;
}