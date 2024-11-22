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

	// ���� ����
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
			// ��� �ǹ��� �������� �ϹǷ�, ���� �� �ð��� �ҿ�Ǵ� ��츦 Ž��
			ans[next] = max(ans[next], ans[now] + time[now]);
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
	// ans[i]�� i�ǹ� �Ǽ��� ������ �ּ� �ð�
	for (num i = 1; i <= N; i++) {
		cout << ans[i] + time[i] << "\n";
	}
}