#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef int num;
num MAX = 2100000000;
typedef pair<num, num> edge; // first는 가중치, second는 노드 번호
num V, E, K;
vector<num> m_distance;
vector<bool> visited;
vector<vector<edge>> m_list;
priority_queue<edge, vector<edge>, greater<edge>> pq;

void _dijkstra();

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> V >> E >> K;
	m_distance.resize(V + 1);
	fill(m_distance.begin(), m_distance.end(), MAX);

	visited.resize(V + 1);
	fill(visited.begin(), visited.end(), false);
	m_list.resize(V + 1);

	num u, v, w;
	for (num i = 0; i < E; i++) {
		cin >> u >> v >> w;
		m_list[u].push_back(edge(w, v));
	}
	_dijkstra();
	for (num i = 1; i <= V; i++) {
		if (visited[i]) cout << m_distance[i] << "\n";
		else cout << "INF\n";
	}
}

void _dijkstra() {
	pq.push(edge(0, K));
	m_distance[K] = 0;
	while (!pq.empty()) {
		edge current = pq.top();
		pq.pop();
		num c_v = current.second;
		if (visited[c_v]) continue;
		visited[c_v] = true;
		for (num i = 0; i < m_list[c_v].size(); i++) {
			edge tmp = m_list[c_v][i];
			num next = tmp.second;
			num value = tmp.first;
			if (m_distance[next] > m_distance[c_v] + value) {
				m_distance[next] = value + m_distance[c_v];
				pq.push(edge(m_distance[next], next));
			}
		}
	}
}