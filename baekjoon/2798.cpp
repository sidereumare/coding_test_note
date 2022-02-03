#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    cin>>N>>M;
    vector<int> arr(N, 0);
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
    int sum = 0, rst = INT32_MAX;
    for(int i = 0; i<N-2; i++){
        sum=arr[i];
        for(int j = i+1; j<N-1; j++){
            sum+=arr[j];
            for(int k = j+1; k<N; k++){
                int t=M-sum-arr[k];
                if(t>=0 && rst>t){
                    rst = t;
                }
            }
            sum-=arr[j];
        }
    }
    cout<<M-rst;
    return 0;
}