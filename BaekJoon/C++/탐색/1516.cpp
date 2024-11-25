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
	num N;
	cin >> N;

	vector<vector<num>> A(N + 1);
	vector<num> indegree(N + 1, 0);
	vector<num> time(N + 1, 0);
	vector<num> ans(N + 1, 0);
	for (num i = 1; i <= N; i++) {
		num a, b;
		cin >> a;
		time[i] = a;
		while (true) {
			cin >> b;
			if (b == -1) break;
			A[b].push_back(i);
			indegree[i]++;
		}
	}

	// 위상 정렬
	queue<num> q;
	for (num i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		num now = q.front();
		q.pop();
		for (num next : A[now]) {
			indegree[next]--;
			// 모든 건물이 지어져야 하므로, 가장 긴 시간이 소요되는 경우를 탐색
			ans[next] = max(ans[next], ans[now] + time[now]);
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
	// ans[i]는 i건물 건설이 가능한 최소 시간
	for (num i = 1; i <= N; i++) {
		cout << ans[i] + time[i] << "\n";
	}
}