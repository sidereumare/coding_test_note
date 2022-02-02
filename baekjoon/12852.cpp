#include <iostream>
#include <algorithm>
using namespace std;
int m[1000005], b[1000005];
int main()
{
	int N;
	cin >> N;
	m[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (i % 3 == 0)
			if (m[i] > m[i / 3] + 1 || m[i] == 0){
				m[i] = m[i / 3] + 1;
                b[i] = i / 3;
            }
		if (i % 2 == 0)
			if (m[i] > m[i / 2] + 1 || m[i] == 0){
				m[i] = m[i / 2] + 1;
                b[i] = i / 2;
            }
		if (m[i] > m[i - 1] + 1 || m[i] == 0){
			m[i] = m[i - 1] + 1;
            b[i] = i - 1;
        }
	}
	cout << m[N] << '\n';
    while(N!=0){
        cout << N << ' ';
        N = b[N];
    }
	return 0;
}