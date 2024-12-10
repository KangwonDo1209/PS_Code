#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long num;

num N, K;
num M = 30;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	vector<vector<num>> A(M + 1);
	for (num i = 0; i <= M; i++) {
		A[i].resize(M + 1);
		A[i][1] = i;
		A[i][i] = 1;
		A[i][0] = 1;
	}
	for (num i = 1; i <= M; i++) {
		for (num j = 1; j <= M; j++) {
			A[i][j] = A[i - 1][j] + A[i - 1][j - 1];
		}
	}

	num T;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		cout << A[K][N] << "\n";
	}
}
