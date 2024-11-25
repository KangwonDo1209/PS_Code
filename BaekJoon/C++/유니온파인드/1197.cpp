#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;
num V, E;
vector<num> parent;
typedef struct Edge {
	num s, e, v;
	bool operator> (const Edge& temp) const {
		return v > temp.v;
	}
};

void unionfunc(num a, num b);
num find(num a);

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> V >> E;
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	// 부모 리스트 초기화
	parent.resize(V + 1);
	for (num i = 1; i <= V; i++) {
		parent[i] = i;
	}
	// 간선 정렬
	for (num i = 0; i < E; i++) {
		num s, e, v;
		cin >> s >> e >> v;
		pq.push(Edge(s, e, v));
	}
	// 크루스칼 알고리즘
	num useEdge = 0;
	num ans = 0;
	while (useEdge < V - 1) { // 간선이 V-1개면 종료
		Edge now = pq.top(); // 사용하지 않은 간선 중 가장 짧은 간선
		pq.pop();
		if (find(now.s) != find(now.e)) { // now 간선이 이미 사용된 간선이 아닐 때
			unionfunc(now.s, now.e); // 사용한 간선 추가
			ans += now.v;
			useEdge++;
		}
	}
	// 결과 출력
	cout << ans;
}
void unionfunc(num a, num b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[b] = a;
}
num find(num a) {
	if (a == parent[a])  return a;
	else return parent[a] = find(parent[a]);
}