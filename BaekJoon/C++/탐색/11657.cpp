#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long num;

num lm = 21000000000;
typedef tuple<num, num, num> edge;
vector<num> distances;
vector<edge> edges;
num N, M;

void bellman_ford(num start);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M;
	distances.resize(N + 1);
	fill(distances.begin(), distances.end(), lm);

	for (num i = 0; i < M; i++) {
		num s, e, t;
		cin >> s >> e >> t;
		edges.push_back(edge(s, e, t));
	}

	bellman_ford(1);
}

void bellman_ford(num start) {
	distances[start] = 0;
	for (num i = 1; i < N; i++) {
		for (num j = 0; j < M; j++) {
			edge medge = edges[j];
			num s = get<0>(medge);
			num e = get<1>(medge);
			num t = get<2>(medge);
			if (distances[s] != lm && distances[e] > distances[s] + t) {
				distances[e] = distances[s] + t;
			}
		}
	}
	bool mCycle = false;
	for (num i = 0; i < M; i++) {
		edge medge = edges[i];
		num s = get<0>(medge);
		num e = get<1>(medge);
		num t = get<2>(medge);
		if (distances[s] != lm && distances[e] > distances[s] + t) {
			mCycle = true;
		}
	}
	if (!mCycle) {
		for (num i = 1; i <= N; i++) {
			if (i == start) continue;
			if (distances[i] == lm)
				cout << -1 << "\n";
			else
				cout << distances[i] << "\n";
		}
	}
	else {
		cout << -1 << "\n";
	}
}