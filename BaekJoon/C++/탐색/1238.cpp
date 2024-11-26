#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;
typedef pair<num, num> edge;
vector<vector<edge>> A;
num lmax = 92233720368547580;
vector<vector<num>> m_distance;
num N, M, X;

void dijkstra(num s);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M >> X;
	m_distance.resize(N + 1);
	for (num i = 0; i <= N; i++) {
		for (num j = 0; j <= N; j++) {
			m_distance[i].push_back(lmax);
		}
	}
	A.resize(N + 1);
	for (num i = 0; i < M; i++) {
		num s, e, w;
		cin >> s >> e >> w;
		A[s].push_back(edge(w, e));
	}
	for (num i = 1; i <= N; i++) {
		dijkstra(i);
	}
	num max = 0;
	for (num i = 1; i <= N; i++) {
		if (i == X) continue;
		num d = m_distance[i][X] + m_distance[X][i];
		if (d > max)
			max = d;
	}
	cout << max;
}

void dijkstra(num s) {
	vector<bool> visited;
	visited.resize(N + 1);
	fill(visited.begin(), visited.end(), false);
	priority_queue<edge, vector<edge>, greater<edge>> pq;
	pq.push(edge(0, s));
	m_distance[s][s] = 0;
	while (!pq.empty()) {
		edge current = pq.top();
		pq.pop();
		num c_v = current.second;
		if (visited[c_v]) continue;
		visited[c_v] = true;
		for (edge tmp : A[c_v]) {
			num next = tmp.second;
			num value = tmp.first;
			if (m_distance[s][next] > m_distance[s][c_v] + value) {
				m_distance[s][next] = m_distance[s][c_v] + value;
				pq.push(pair(m_distance[s][next], next));
			}
		}
	}
}