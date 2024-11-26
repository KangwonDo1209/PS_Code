#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;
typedef pair<num, num> edge;
vector<vector<edge>> A;
num lmax = 9223372036854758;

num N, E, a, b;

void dijkstra(vector<num>& m_distance, num s);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> E;
	vector<num> s_distance;
	vector<num> a_distance;
	vector<num> b_distance;
	s_distance.resize(N + 1);
	a_distance.resize(N + 1);
	b_distance.resize(N + 1);
	fill(s_distance.begin(), s_distance.end(), lmax);
	fill(a_distance.begin(), a_distance.end(), lmax);
	fill(b_distance.begin(), b_distance.end(), lmax);
	A.resize(N + 1);
	for (num i = 0; i < E; i++) {
		num s, e, w;
		cin >> s >> e >> w;
		A[s].push_back(edge(w, e));
		A[e].push_back(edge(w, s));
	}
	cin >> a >> b;
	dijkstra(s_distance, 1);
	dijkstra(a_distance, a);
	dijkstra(b_distance, b);
	num A = s_distance[a] + a_distance[b] + b_distance[N];
	num B = s_distance[b] + a_distance[N] + b_distance[a];
	num ans = ((A >= lmax && B >= lmax) ? -1 : (A > B ? B : A));

	cout << ans;
}

void dijkstra(vector<num>& m_distance, num s) {
	vector<bool> visited;
	visited.resize(N + 1);
	fill(visited.begin(), visited.end(), false);
	priority_queue<edge, vector<edge>, greater<edge>> pq;
	pq.push(edge(0, s));
	m_distance[s] = 0;
	while (!pq.empty()) {
		edge current = pq.top();
		pq.pop();
		num c_v = current.second;
		if (visited[c_v]) continue;
		visited[c_v] = true;
		for (edge tmp : A[c_v]) {
			num next = tmp.second;
			num value = tmp.first;
			if (m_distance[next] > m_distance[c_v] + value) {
				m_distance[next] = m_distance[c_v] + value;
				pq.push(pair(m_distance[next], next));
			}
		}
	}
}