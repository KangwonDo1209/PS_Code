#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef long long num;

/*
*	최소의 비용으로 모든 도시를 연결해야하므로, 최소 스패닝 트리를 이용한다.
*	최소 스패닝 트리는  union-find 를 이용해 구현한다.
*	시간 복잡도는 MlogN 이다.
*/
struct Edge {
	num s, e, v;
	Edge(num start, num end, num value) : s(start), e(end), v(value) {}
	bool operator> (const Edge& temp) const {
		return v > temp.v;
	}
};
num N, M, K;
vector<num> parent;
void unionfunc(num a, num b);
num find(num a);
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	cin >> N >> M >> K;
	parent.resize(N + 1);
	for (num i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (num i = 0; i < M; i++) {
		num u, v, c;
		cin >> u >> v >> c;
		pq.push(Edge(u, v, c));
	}
	for (num i = 0; i < K; i++) {
		num a, b, c;
		cin >> a >> b >> c;
	}
	num useEdge = 0;
	num ans = 0;
	while (useEdge < N - 1 && !pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		if (find(now.s) != find(now.e)) {
			unionfunc(now.s, now.e);
			ans += now.v;
			useEdge++;
		}
	}
	if (useEdge == N - 1)
		cout << ans;
	else
		cout << -1;

}

void unionfunc(num a, num b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[b] = a;
}
num find(num a) {
	if (a == parent[a]) return a;
	else return parent[a] = find(parent[a]);
}