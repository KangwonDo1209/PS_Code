#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;

vector<num> parent;
num N, M;
num ans = 0;
num cnt = 0;
void _union(num a, num b);
num _find(num a);
bool _check(num a, num b);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M;
	parent.resize(N);
	for (num i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (num i = 0; i < M; i++) {
		cnt++;
		num a, b;
		cin >> a >> b;
		_union(a, b);
	}
	cout << ans;
}

void _union(num a, num b) {
	num ap = _find(a);
	num bp = _find(b);
	if (ap != bp) parent[bp] = ap;
	else {
		if (ans == 0) {
			ans = cnt;
		}
	}
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
