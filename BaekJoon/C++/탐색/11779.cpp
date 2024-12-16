#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;
typedef pair<num, num> edge;

num INF = 999999999999;
vector<bool> visited;
vector<vector<edge>> A;
vector<num> route;
vector<num> distances;

num N, M;
num S, E;

void dijkstra(num start);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M;
	distances.resize(N + 1, INF);
	visited.resize(N + 1, false);
	A.resize(N + 1);
	route.resize(N + 1);
	num a, b, c;
	for (num i = 0; i < M; i++) {
		cin >> a >> b >> c;
		A[a].push_back(edge(c, b));
	}
	cin >> S >> E;

	dijkstra(S);
	cout << distances[E] << "\n";
	vector<num> ans2;
	num p = E;
	num cnt = 0;
	while (true) {
		ans2.insert(ans2.begin(), p);
		cnt++;
		if (p == route[p]) break;
		p = route[p];
	}
	cout << cnt << "\n";
	for (num tmp : ans2) {
		cout << tmp << " ";
	}
}

void dijkstra(num start) {
	priority_queue<edge, vector<edge>, greater<edge>> pq;
	pq.push(edge(0, start));
	distances[start] = 0;
	route[start] = start;
	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();
		num c_v = now.second;
		if (visited[c_v]) continue;
		visited[c_v] = true;
		for (edge tmp : A[c_v]) {
			num next = tmp.second;
			num value = tmp.first;
			if (distances[next] > distances[c_v] + value) {
				distances[next] = distances[c_v] + value;
				// 경로 저장
				// next까지의 경로 = c_v까지의 경로 + next
				// route[i]는 i까지 가는 최단경로의 i 이전 노드
				// route를 통해 노드를 타고 올라가 start까지 가면 경로를 구할 수 있음
				route[next] = c_v;
				pq.push(edge(distances[next], next));
			}
		}
	}
}