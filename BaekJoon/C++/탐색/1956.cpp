#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long num;

num N, M;

num A[401][401];
num lm = 9999999999999;

void floyd_warshall();

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M;
	num a, b, c;
	for (num i = 1; i <= N; i++) {
		for (num j = 1; j <= N; j++) {
			if (i == j) A[i][j] = 0;
			else A[i][j] = lm;
		}
	}
	for (num i = 0; i < M; i++) {
		cin >> a >> b >> c;
		A[a][b] = c;
	}
	floyd_warshall();
	num ans = lm;
	for (num i = 1; i <= N; i++) {
		for (num j = 1; j <= N; j++) {
			if (i == j) continue;
			num l = A[i][j] + A[j][i];
			ans = min(ans, l);
		}
	}
	if (ans == lm)
		cout << -1;
	else
		cout << ans;
}

void floyd_warshall() {
	for (num k = 1; k <= N; k++) {
		for (num i = 1; i <= N; i++) {
			for (num j = 1; j <= N; j++) {
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
	}
}