#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;

num lmin = -92233720368547580;
num lmax = 92233720368547580;
typedef tuple<num, num, num> edge;
vector<num> distances;
vector<edge> edges;
vector<num> cityValue;
vector<bool> cityCycle;
num N, A, B, M;

void bellman_ford(num start);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> A >> B >> M;
	distances.resize(N);
	cityCycle.resize(N);
	cityValue.resize(N);
	fill(distances.begin(), distances.end(), lmin);

	for (num i = 0; i < M; i++) {
		num s, e, t;
		cin >> s >> e >> t;
		edges.push_back(edge(s, e, t));
	}
	for (num i = 0; i < N; i++) {
		cin >> cityValue[i];
	}
	bellman_ford(A);
}
// 변형된 벨만포드 알고리즘
void bellman_ford(num start) {
	distances[start] = cityValue[start];
	for (num i = 0; i < N + 100; i++) { // 사이클의 영향이 모든 노드에 퍼지기 위한 충분한 반복 추가(+100)
		for (num j = 0; j < M; j++) {
			edge medge = edges[j];
			num s = get<0>(medge);
			num e = get<1>(medge);
			num cost = get<2>(medge);
			if (distances[s] == lmin) continue;
			else if (distances[s] == lmax) {
				distances[e] = lmax;
			}
			else if (distances[e] < distances[s] + cityValue[e] - cost) {
				distances[e] = distances[s] + cityValue[e] - cost;
				if (i >= N - 1) // N-1번 탐색 완료 후에도 돈이 더 큰 값을 탐색하면, 사이클이 존재함
					distances[e] = lmax;
			}
		}
	}
	if (distances[B] == lmin) cout << "gg\n";
	else if (distances[B] == lmax) cout << "Gee\n";
	else cout << distances[B] << '\n';
}