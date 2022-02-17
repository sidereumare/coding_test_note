#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int x, y, w, h;
    cin>>x>>y>>w>>h;
    cout<<min({abs(x-w), x, abs(y-h), y});
    return 0;
}