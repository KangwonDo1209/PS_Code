#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef long long num;

/*
*	모든 도시간의 최단 거리를 구해야므로, 플로이드-워셜 알고리즘을 사용한다.
*	플로이드-워셜 알고리즘의 시간 복잡도는 N^3이다.
*/
num lmax = 999999999999;
num A[101][101];

num N, M;

void floyd_warshall();
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	fill(&A[0][0], &A[100][100], lmax);
	cin >> N >> M;
	for (num i = 1; i <= N; i++) {
		A[i][i] = 0;
	}
	for (num i = 0; i < M; i++) {
		num a, b, c;
		cin >> a >> b >> c;
		A[a][b] = c;
	}
	floyd_warshall();
	for (num i = 1; i <= N; i++) {
		for (num j = 1; j <= N; j++) {
			if (A[i][j] >= lmax)
				cout << "INF ";
			else
				cout << A[i][j] << " ";
		}
		cout << "\n";
	}
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