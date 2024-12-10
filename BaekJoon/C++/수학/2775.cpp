#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long num;

num N, K;
num M = 14;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	vector<vector<num>> A(M + 1);
	for (num i = 0; i <= M; i++) {
		A[i].resize(M + 1);
		A[0][i] = i;
		A[i][0] = 0;
	}
	for (num i = 1; i <= M; i++) {
		for (num j = 1; j <= M; j++) {
			A[i][j] = A[i][j - 1] + A[i - 1][j];
		}
	}

	num T;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		cout << A[N][K] << "\n";
	}
}
