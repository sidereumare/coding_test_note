#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string dp[103];
vector<string> path;
//20이하일 때
bool chk = true;
string string_add(string a, string b) {
	int sum = 0;
	string result;
	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

string hanoi(int n, int from, int to){
    if(n==0){
        return "0";
    }
    int move = 6-from-to;
    string cnt = "0";
    if(chk){
        cnt=string_add(hanoi(n-1, from, move), cnt);
        path.push_back(to_string(from)+" "+to_string(to));
        cnt=string_add(hanoi(n-1, move, to), cnt);
        return string_add(cnt, "1");
    }else{
        if(dp[n]!="-1"){
            return dp[n];
        }
        cnt = string_add(hanoi(n-1, 1, 3), cnt);
        cnt = string_add(cnt, cnt);
        dp[n] = string_add(cnt, "1");
        return dp[n];
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    dp[1] = 1;
    for(int i = 0; i<103; i++){
        dp[i] = "-1";
    }
    if(N>20){
        chk = false;
    }
    dp[0] = "0";
    dp[1] = "1";
    cout<<hanoi(N, 1, 3)<<'\n';
    for(string& t: path){
        cout<<t<<'\n';
    }
    return 0;
}