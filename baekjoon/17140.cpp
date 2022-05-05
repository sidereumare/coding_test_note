// #include <bits/stdc++.h>
// using namespace std;
// int r, c, k;
// int arr[103][103];
// bool cmp(const pair<int, int>&a, const pair<int,int> &b){
//     if(a.second==b.second){
//         return a.first<b.first;
//     }
//     return a.second<b.second;
// }
// int main(){
//     cin>>r>>c>>k;
//     int row=3, col=3;
//     for(int i = 1; i<=3; i++){
//         for(int j = 1; j<=3; j++){
//             cin>>arr[i][j];
//         }
//     }
//     for(int i = 0; i<=100; i++){
//         if(arr[r][c]==k){
//             cout<<i;
//             return 0;
//         }
//         map<int, int> m;
//         int row_=0, col_=0;
//         if(col<=row){
//             for(int j = 1; j<=row; j++){
//                 m.clear();
//                 for(int k = 1; k<=col; k++){
//                     if(arr[j][k]!=0){
//                         m[arr[j][k]]++;
//                     }
//                 }
//                 vector<pair<int, int> > v(m.begin(), m.end());
//                 sort(v.begin(), v.end(), cmp);
//                 for(int k = 0; k<min((int)v.size(),50); k++){
//                     arr[j][k*2+1] = v[k].first;
//                     arr[j][k*2+2] = v[k].second;
//                 }
//                 for(int k = min((int)v.size(),50)*2+1; k<=col; k++){
//                     arr[j][k] = 0;
//                 }
//                 col_ = min(max((int)m.size()*2, col_),100);
//             }
//             col = col_;
//         }else{
//             for(int j = 1; j<=col; j++){
//                 m.clear();
//                 for(int k = 1; k<=row; k++){
//                     if(arr[k][j]!=0){
//                         m[arr[k][j]]++;
//                     }
//                 }
//                 vector<pair<int, int> > v(m.begin(), m.end());
//                 sort(v.begin(), v.end(), cmp);
//                 for(int k = 0; k<min((int)v.size(),50); k++){
//                     arr[k*2+1][j] = v[k].first;
//                     arr[k*2+2][j] = v[k].second;
//                 }
//                 for(int k = min((int)v.size(),50)*2+1; k<=row; k++){
//                     arr[k][j] = 0;
//                 }
//                 row_ = min(max((int)m.size()*2, row_),100);
//             }
//             row = row_;
//         }
//     }
//     cout<<-1;
//     return 0;
// }

#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<deque>
using namespace std;
int r, c, k;
int arr[101][101];
int C = 3, R = 3;//R은 가로길이 C=세로
int dp[101];

bool compare(const pair<int, int>& p1, const pair<int, int>& p2)
{
	if (p1.second == p2.second)
		return p1.first < p2.first;
	else
		return p1.second < p2.second;
}

void ArrayR()
{
	int maxR = 0;
	for (int i = 1; i <= C; i++)
	{
		int tmp = 1;
		deque<pair<int, int>> v;
		memset(dp, 0, sizeof(dp));
		for (int j = 1; j <= R; j++)
		{
			dp[arr[i][j]]++;
		}

		for (int j = 1; j <101; j++)
		{
			if (dp[j] != 0)
				v.push_back({j, dp[j] });
		}
		
		sort(v.begin(), v.end(), compare);
		while (tmp<101)
		{
			if (v.empty())
				arr[i][tmp++] = 0;
			else
			{
				arr[i][tmp++] = v.front().first;
				arr[i][tmp++] = v.front().second;
				v.pop_front();
				maxR = max(maxR, tmp-1);
			}
			
		}
	}
	R = maxR;
}
void ArrayC()
{
	int maxC = 0;
	for (int j = 1; j <= R; j++)
	{
		int tmp = 1;
		deque<pair<int, int>> v;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= C; i++)
		{
			dp[arr[i][j]]++;
		}
		
		for (int i = 1; i < 101; i++)
		{
			if (dp[i] != 0)
				v.push_back({ i, dp[i] });
		}
		sort(v.begin(), v.end(), compare);
		while (tmp < 101)
		{
			if (v.empty())
				arr[tmp++][j] = 0;
			else
			{
				arr[tmp++][j] = v.front().first;
				arr[tmp++][j] = v.front().second;
				v.pop_front();
				maxC = max(maxC, tmp - 1);
			}
		}
	}
	C = maxC;
}
	
void print()
{
	for (int i = 1; i <= C; i++)
	{
		for (int j = 1; j <= R; j++)
			cout << arr[i][j];
		cout << endl;
	}
	cout << endl;
}

int solve()
{
	int t = 0;
	if (arr[r][c] == k) return t;
	while (t<101) {
		if (R <= C)	ArrayR();
		else	ArrayC();
		t++;
		if (arr[r][c] == k) return t;
	}
	return -1;
}

int main()
{
	cin >> r >> c >> k;
	for (int i = 1; i <=C; i++)
	{
		for (int j = 1; j <=R; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << solve();
}