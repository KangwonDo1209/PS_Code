#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long num;
num n, m;
vector<num> parent;
vector<num> know;
vector<vector<num>> party;

void unionfunc(num a, num b);
num find(num a);

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	num ans = 0;
	num n, m, t;
	cin >> n >> m >> t;

	// 부모 노드 초기화
	parent.resize(n + 1);
	for (num i = 1; i <= n; i++) {
		parent[i] = i;
	}
	// 아는 사람
	know.resize(t);
	for (num i = 0; i < t; i++) {
		cin >> know[i];
	}
	// 파티
	party.resize(m);
	for (num i = 0; i < m; i++) {
		num k, x, y;
		cin >> k >> x;
		party[i].push_back(x);
		for (num j = 0; j < k - 1; j++) {
			cin >> y;
			unionfunc(x, y);
			party[i].push_back(y);
		}
	}
	// 정답 카운트
	for (num i = 0; i < m; i++) {
		bool isvalid = true;
		num f_first = find(party[i][0]);
		for (num j = 0; j < t; j++) {
			if (f_first == find(know[j]))
				isvalid = false;
		}
		if (isvalid) ans++;
	}
	cout << ans;
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