#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long num;
num n, m;
vector<num> parent;
num city[201][201];
num route[1001];

void unionfunc(num a, num b);
num find(num a);

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	num l;
	cin >> n >> m;
	parent.resize(n + 1);

	for (num i = 1; i <= n; i++) {
		for (num j = 1; j <= n; j++) {
			cin >> city[i][j];
		}
	}
	for (num i = 1; i <= m; i++) {
		cin >> route[i];
	}
	for (num i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (num i = 1; i <= n; i++) {
		for (num j = 1; j <= n; j++) {
			if (city[i][j]) unionfunc(i, j);
		}
	}

	num index = find(route[1]);
	bool connect = true;
	for (num i = 2; i <= m; i++) {
		if (index != find(route[i])) {
			cout << "NO\n";
			connect = false;
			break;
		}
	}
	if (connect) 	cout << "YES\n";
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