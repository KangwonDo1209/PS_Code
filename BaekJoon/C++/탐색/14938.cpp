#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;
typedef pair<num, num> edge;
num A[101][101];
num T[101];
num lmax = 9223372036854758;

num N, M, R;

void floyd_warshall();

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M >> R;
	for (num i = 1; i <= N; i++) {
		for (num j = 1; j <= N; j++) {
			if (i == j) A[i][j] = 0;
			else A[i][j] = lmax;
		}
	}
	for (num i = 1; i <= N; i++) {
		cin >> T[i];
	}
	for (num i = 0; i < R; i++) {
		num a, b, l;
		cin >> a >> b >> l;
		A[a][b] = l;
		A[b][a] = l;
	}
	floyd_warshall();
	num max = 0;
	for (num i = 1; i <= N; i++) {
		num sum = 0;
		for (num j = 1; j <= N; j++) {
			if (A[i][j] <= M)
				sum += T[j];
		}
		max = (max > sum ? max : sum);
	}
	cout << max;
}

void floyd_warshall() {
	for (num k = 1; k <= N; k++) {
		for (num i = 1; i <= N; i++) {
			for (num j = 1; j <= N; j++) {
				if (A[i][j] > A[i][k] + A[k][j])
					A[i][j] = A[i][k] + A[k][j];
			}
		}
	}
}