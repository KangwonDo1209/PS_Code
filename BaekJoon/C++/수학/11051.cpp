#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long num;

num N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> K;
	vector<vector<num>> A(N + 1);
	for (num i = 0; i <= N; i++) {
		A[i].resize(N + 1);
		A[i][1] = i;
		A[i][0] = 1;
		A[i][i] = 1;
	}
	for (num i = 2; i <= N; i++) {
		for (num j = 1; j <= i; j++) {
			A[i][j] = (A[i - 1][j] + A[i - 1][j - 1]) % 10007;
		}
	}
	cout << A[N][K];

}
