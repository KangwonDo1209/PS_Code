#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;

struct node {
	num s, e, v;
	bool operator< (const node& temp) const {
		return v < temp.v;
	}
};

num N, M;
num f1, f2;

void _union(num a, num b);
num _find(num a);
bool _check(num a, num b);

vector<num> parent;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M;
	parent.resize(N + 1);
	for (num i = 1; i <= N; i++) {
		parent[i] = i;
	}

	priority_queue<node, vector<node>, less<node>> pq;
	num a, b, c;
	for (num i = 0; i < M; i++) {
		cin >> a >> b >> c;
		pq.push(node(a, b, c));
	}
	cin >> f1 >> f2;
	num ans = 0;

	// pq�� ������������ ���ǵǾ� �����Ƿ�, �������� f1�� f2�� ����� ������ �߷�������
	//  f1�� f2�� ���ῡ�� �ּ� �߷� ������ �ִ밪��.
	while (!pq.empty()) {
		node a = pq.top();
		pq.pop();
		_union(a.s, a.e);
		if (_find(f1) == _find(f2)) {
			ans = a.v;
			break;
		}
	}
	cout << ans;
}

void _union(num a, num b) {
	num ap = _find(a);
	num bp = _find(b);
	if (ap != bp) parent[bp] = ap;
}
num _find(num a) {
	if (a == parent[a]) return a;
	else return parent[a] = _find(parent[a]);
}
bool _check(num a, num b) {
	num ap = _find(a);
	num bp = _find(b);
	return ap == bp;
}