#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;
num N;
vector<num> parent;
num adj[51][51];

typedef struct Edge {
	num s, e, v;
	bool operator> (const Edge& temp) const {
		return v > temp.v;
	}
};
num convert(char c);
void unionfunc(num a, num b);
num find(num a);

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	num total = 0;
	cin >> N;
	parent.resize(N);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	// 입력
	for (num i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (num j = 0; j < N; j++) {
			num e = convert(str[j]);
			total += e;
			if (e != 0) pq.push(Edge(i, j, e));
		}
	}
	// 부모 배열 초기화
	for (num i = 0; i < N; i++) {
		parent[i] = i;
	}
	// 크루스칼 알고리즘
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
	// 출력
	if (useEdge == N - 1) cout << total - ans;
	else cout << -1;
}
num convert(char c) {
	if (c >= 'a' && c <= 'z') return (num)(c - 'a' + 1);
	else if (c >= 'A' && c <= 'Z') return(num)(c - 'A' + 27);
	else return 0;
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