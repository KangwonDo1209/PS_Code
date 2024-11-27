#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;
typedef pair<num, num> edge;
typedef pair<num, num> city;
num A[201][201];
num lmax = 9223372036854758;

num N, M, K;
/*
* 각 친구의 도시에서 다른 도시로의 왕복시간을 모두 구한다.
* 도시별로 친구들의 왕복시간의 최대값을 (최대값, 도시번호)으로 우선순위 큐에 넣는다.
* 우선순위 큐의 최대값 부분이 바뀔때까지 도시 번호를 출력한다.
*/
void floyd_warshall();

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M;
	for (num i = 1; i <= N; i++) {
		for (num j = 1; j <= N; j++) {
			if (i == j) A[i][j] = 0;
			else A[i][j] = lmax;
		}
	}
	for (num i = 0; i < M; i++) {
		num a, b, l;
		cin >> a >> b >> l;
		A[a][b] = l;
	}
	floyd_warshall();
	cin >> K;
	vector<num> f_city(K);
	for (num i = 0; i < K; i++) {
		cin >> f_city[i];
	}
	priority_queue<city, vector<city>, greater<city>> pq;
	for (num i = 1; i <= N; i++) {
		num max = 0;
		for (num j = 0; j < K; j++) {
			num t = A[i][f_city[j]] + A[f_city[j]][i];
			if (max < t && t < lmax) {
				max = t;
			}
		}
		pq.push(city(max, i));
	}
	num pre = lmax;
	while (!pq.empty()) {
		if (pre < pq.top().first) break;
		cout << pq.top().second << " ";
		pre = pq.top().first;
		pq.pop();
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