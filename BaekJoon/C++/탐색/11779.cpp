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
				// ��� ����
				// next������ ��� = c_v������ ��� + next
				// route[i]�� i���� ���� �ִܰ���� i ���� ���
				// route�� ���� ��带 Ÿ�� �ö� start���� ���� ��θ� ���� �� ����
				route[next] = c_v;
				pq.push(edge(distances[next], next));
			}
		}
	}
}