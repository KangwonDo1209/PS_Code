#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef int num;

void _union(num a, num b);
num _find(num a);
bool _check(num a, num b);

vector<num> parent;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	num n, m;
	cin >> n >> m;
	num k, a, b;
	parent.resize(n + 1);
	for (num i = 0; i <= n; i++) {
		parent[i] = i;
	}
	while (m--) {
		cin >> k >> a >> b;
		if (k == 0) _union(a, b);
		else cout << (_check(a, b) ? "YES" : "NO") << "\n";
	}
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

