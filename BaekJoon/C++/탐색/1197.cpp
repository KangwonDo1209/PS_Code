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
	// �θ� ����Ʈ �ʱ�ȭ
	parent.resize(V + 1);
	for (num i = 1; i <= V; i++) {
		parent[i] = i;
	}
	// ���� ����
	for (num i = 0; i < E; i++) {
		num s, e, v;
		cin >> s >> e >> v;
		pq.push(Edge(s, e, v));
	}
	// ũ�罺Į �˰���
	num useEdge = 0;
	num ans = 0;
	while (useEdge < V - 1) { // ������ V-1���� ����
		Edge now = pq.top(); // ������� ���� ���� �� ���� ª�� ����
		pq.pop();
		if (find(now.s) != find(now.e)) { // now ������ �̹� ���� ������ �ƴ� ��
			unionfunc(now.s, now.e); // ����� ���� �߰�
			ans += now.v;
			useEdge++;
		}
	}
	// ��� ���
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