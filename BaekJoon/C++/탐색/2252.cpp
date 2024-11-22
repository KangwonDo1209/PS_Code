#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef int num;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	num N, M;
	cin >> N >> M;

	vector<vector<num>> A(N + 1);
	vector<num> indegree(N + 1, 0);
	for (num i = 0; i < M; i++) {
		num a, b;
		cin >> a >> b;
		A[a].push_back(b);
		indegree[b] += 1;
	}

	// 위상 정렬
	queue<num> q;
	for (num i = 1; i <= N; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		num now = q.front();
		q.pop();
		cout << now << " ";
		for (num next : A[now]) {
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}
}