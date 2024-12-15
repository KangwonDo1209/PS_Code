#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;
// first: ����� ���� ��, second: ��� ����
typedef pair<num, num> node;

num N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> K;
	vector<num> V(N);
	for (num i = 0; i < N; i++) {
		cin >> V[i];
	}
	num ans = -1;
	// BFS ������� �ִܰŸ�(�ּ� ����)�� ���Ѵ�.
	queue<node> q;
	vector<bool> visited(K + 1);
	q.push(node(0, 0));
	visited[0] = true;
	while (!q.empty()) {
		node current = q.front();
		q.pop();
		for (num i = 0; i < N; i++) {
			num next_value = current.second + V[i];
			if (next_value > K || visited[next_value]) continue;
			q.push(node(current.first + 1, next_value));
			visited[next_value] = true;
			if (next_value == K)
				ans = current.first + 1;
		}
	}
	cout << ans;

}
