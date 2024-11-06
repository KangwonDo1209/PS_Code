#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef int num;
typedef pair<num, num> edge;
num _max = 2100000000;
num N, M, A, B;
vector<bool> visited;
vector<vector<edge>> m_list;
vector<num> m_distance;
priority_queue<edge, vector<edge>, greater<edge>> pq;

void dijkstra();

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M;
	visited.resize(N + 1);
	m_list.resize(N + 1);
	m_distance.resize(N + 1);
	fill(m_distance.begin(), m_distance.end(), _max);
	fill(visited.begin(), visited.end(), false);

	num u, v, w;
	for (num i = 0; i < M; i++) {
		cin >> u >> v >> w;
		m_list[u].push_back(edge(w, v));
	}
	cin >> A >> B;
	dijkstra();
	cout << m_distance[B];
}

void dijkstra() {
	pq.push(edge(0, A));
	m_distance[A] = 0;
	while (!pq.empty()) {
		edge current = pq.top();
		pq.pop();
		num c_v = current.second;
		if (visited[c_v]) continue;
		visited[c_v] = true;
		for (num i = 0; i < m_list[c_v].size(); i++) {
			edge tmp = m_list[c_v][i];
			num value = tmp.first;
			num next = tmp.second;
			if (m_distance[next] > m_distance[c_v] + value) {
				m_distance[next] = m_distance[c_v] + value;
				pq.push(edge(m_distance[next], next));
			}
		}
	}
}
