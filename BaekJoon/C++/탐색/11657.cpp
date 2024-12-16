#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;
typedef tuple<num, num, num> edge;

vector<num> distances;
vector<edge> edges;
num lm = 999999999999;

num N, M;

bool bellman_ford(num start);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M;
	distances.resize(N + 1, lm);

	num a, b, c;
	for (num i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edges.push_back(edge(a, b, c));
	}
	bool hasCycle = bellman_ford(1);

	if (hasCycle) {
		cout << -1;
	}
	else {
		for (num i = 2; i <= N; i++) {
			if (distances[i] == lm)
				cout << -1 << "\n";
			else
				cout << distances[i] << "\n";
		}
	}

}

bool bellman_ford(num start) {
	distances[start] = 0;
	for (num i = 0; i < N - 1; i++) {
		for (num j = 0; j < M; j++) {
			edge medge = edges[j];
			num s = get<0>(medge);
			num e = get<1>(medge);
			num t = get<2>(medge);
			// start에서 s까지 가는 경로가 탐색 되었고,
			// e까지 더 짧은 경로를 찾으면 갱신
			if (distances[s] != lm && distances[e] > distances[s] + t) {
				distances[e] = distances[s] + t;
			}
		}
	}
	bool hasCycle = false;
	for (num i = 0; i < M; i++) {
		edge medge = edges[i];
		num s = get<0>(medge);
		num e = get<1>(medge);
		num t = get<2>(medge);
		// start에서 s까지 가는 경로가 탐색 되었고,
		// e까지 가는 더 짧은 경로를 찾는 경우, 음수 사이클이 존재하는 것임.
		// 음수 사이클이 없다면, 이미 모두 갱신되었을것임.
		// 즉, 더 짧은 경로가 발견 된다는 것은 음수 사이클이 존재한다는 것임.
		if (distances[s] != lm && distances[e] > distances[s] + t) {
			hasCycle = true;
		}
	}
	return hasCycle;
}