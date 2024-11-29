#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef long long num;

/*
*	음수 사이클의 존재 여부를 구해야하므로, 벨만-포드 알고리즘을 사용한다.
*	벨만-포드 알고리즘의 시간 복잡도는 O(VE) 이다.
*/
num lmax = 999999999999;
typedef tuple<num, num, num> edge;
vector<num> distances;
vector<edge> edges;

num V, E;
bool bellman_ford(num start);
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> V >> E;
	distances.resize(V + 1);
	fill(distances.begin(), distances.end(), lmax);
	for (num i = 0; i < E; i++) {
		num u, v, w;
		cin >> u >> v >> w;
		edges.push_back(edge(u, v, w));
	}
	cout << (bellman_ford(1) ? "YES" : "NO");
}
bool bellman_ford(num start) {
	distances[start] = 0;
	for (num i = 0; i < V - 1; i++) {
		for (num j = 0; j < E; j++) {
			edge medge = edges[j];
			num s = get<0>(medge);
			num e = get<1>(medge);
			num t = get<2>(medge);
			if (distances[s] != lmax && distances[e] > distances[s] + t) {
				distances[e] = distances[s] + t;
			}
		}
	}
	bool hasCycle = false;
	for (num i = 0; i < E; i++) {
		edge medge = edges[i];
		num s = get<0>(medge);
		num e = get<1>(medge);
		num t = get<2>(medge);
		if (distances[s] != lmax && distances[e] > distances[s] + t) {
			hasCycle = true;
		}
	}
	return hasCycle;
}

