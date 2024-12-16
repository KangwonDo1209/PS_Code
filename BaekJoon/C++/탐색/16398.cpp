#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;

struct node {
	num s, e, v;
	bool operator> (const node& temp)const {
		return v > temp.v;
	}
};

vector<vector<num>> A;
vector<num> parent;
num N;

void _union(num a, num b);
num _find(num a);
bool _check(num a, num b);
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N;
	A.resize(N + 1);
	parent.resize(N + 1);
	for (num i = 1; i <= N; i++) {
		A[i].resize(N + 1);
		for (num j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	priority_queue<node, vector<node>, greater<node>> pq;
	for (num i = 1; i <= N; i++) {
		for (num j = 1; j <= N; j++) {
			if (i == j) continue;
			num v = A[i][j];
			pq.push(node(i, j, v));
		}
	}
	for (num i = 1; i <= N; i++) {
		parent[i] = i;
	}

	num ans = 0;
	num cnt = 0;
	while (cnt < N - 1) {
		node a = pq.top();
		pq.pop();
		if (_check(a.s, a.e)) continue;
		_union(a.s, a.e);
		ans += a.v;
		cnt++;
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