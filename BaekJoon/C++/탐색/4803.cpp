#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;
typedef int num;

vector<vector<num>> A;
vector<num> visited;
num ans = 0;
num dfs(num index);

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	num t = 1;
	while (true) {
		num n, m, a, b;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		A.clear();
		visited.clear();
		ans = 0;
		A.resize(n + 1);
		visited = vector<num>(n + 1, 0);
		for (num i = 0; i < m; i++) {
			cin >> a >> b;
			A[a].push_back(b);
			A[b].push_back(a);
		}

		for (num i = 1; i <= n; i++) {
			ans += dfs(i);
		}
		string str = "Case " + to_string(t++) + ": ";
		if (ans == 0)
			str += "No trees.\n";
		else if (ans == 1)
			str += "There is one tree.\n";
		else
			str += "A forest of " + to_string(ans) + " trees.\n";
		cout << str;
	}
}

num dfs(num index) {
	if (visited[index]) return 0;
	num istree = 1;
	stack<num> stk;
	stk.push(index);
	while (!stk.empty()) {
		num node = stk.top(); stk.pop();
		for (num i : A[node]) {
			if (visited[node] == i) continue;
			if (visited[i]) {
				istree = 0;
				continue;
			}
			visited[i] = node;
			stk.push(i);
		}
	}
	return istree;
}