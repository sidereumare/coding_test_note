#include <iostream>
#include <vector>
#define M 1000005
using namespace std;

bool chkp[M] = {0, };
vector<int> prime;
void getprime(){
    for(int i = 2; i<M; i++){
        chkp[i] = true;
    }
    for(int i = 2; i*i<M; i++){
        if(chkp[i]){
            prime.push_back(i);
            for(int j = i*i; j<M; j+=i){
                chkp[j] = false;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    getprime();
    while(true){
        int n;
        bool chk = true;
        cin>>n;
        if(n==0){
            break;
        }
        for(auto t: prime){
            if(chkp[n-t]){
                chk = false;
                cout<<n<<" = "<<t<<" + "<<n-t<<'\n';
                break;
            }
        }
        if(chk){
            cout<<"Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}