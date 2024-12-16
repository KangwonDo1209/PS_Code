#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;

num N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M;

	vector<vector<num>> A(N + 1);
	vector<num> indegree(N + 1, 0);
	vector<num> ans(N + 1, 0);
	num a, b;
	for (num i = 0; i < M; i++) {
		cin >> a >> b;
		A[a].push_back(b);
		indegree[b] += 1;
	}
	queue<num> q;
	for (num i = 1; i <= N; i++) {
		if (indegree[i] == 0) q.push(i);
		ans[i] = 1;
	}
	while (!q.empty()) {
		num now = q.front();
		q.pop();
		for (num next : A[now]) {
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
				ans[next] = ans[now] + 1;
			}
		}
	}
	for (num i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
}
