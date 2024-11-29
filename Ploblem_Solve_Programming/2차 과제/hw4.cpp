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
num lmax = 9999;
num A[11][11];
num ans;
num N, M, K;
num route[11];
bool visited[11];
void floyd_warshall();
void travel(num now, num depth, num len);
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M >> K;
	fill(&A[0][0], &A[10][10], lmax);
	for (num i = 1; i <= 10; i++) {
		A[i][i] = 0;
	}
	for (num i = 0; i < M; i++) {
		num a, b;
		cin >> a >> b;
		A[a][b] = 1;
		A[b][a] = 1;
	}
	floyd_warshall();
	for (num i = 0; i < K; i++) {
		cin >> route[i];
		visited[i] = false;
	}
	ans = lmax;
	for (num i = 0; i < K; i++) {
		visited[i] = true;
		travel(i, 0, 0);
		visited[i] = false;
	}
	if (ans == lmax) cout << -1;
	else cout << ans;
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

void travel(num now, num depth, num len) {
	if (depth == K-1) {
		ans = min(ans, len);
		return;
	}
	for (num next = 0; next < K; next++) {
		if (visited[next])  continue;
		visited[next] = true;
		travel(next, depth + 1, len + A[route[now]][route[next]]);
		visited[next] = false;
	}
}