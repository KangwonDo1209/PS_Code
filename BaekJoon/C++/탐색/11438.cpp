#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long num;
num N, M;
num kmax;
vector<vector<num>> tree;
vector<num> depth;
num parent[21][100001];
vector<bool> visited;

void BFS(num start);
num excuteLCA(num a, num b);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N;
	tree.resize(N + 1);
	visited.resize(N + 1);
	depth.resize(N + 1);
	fill(visited.begin(), visited.end(), false);
	for (num i = 0; i < N - 1; i++) {
		num a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	num temp = 1;
	kmax = 0;
	while (temp <= N) {
		temp <<= 1;
		kmax++;
	}
	BFS(1);
	for (num k = 1; k <= kmax; k++) {
		for (num n = 1; n <= N; n++) {
			parent[k][n] = parent[k - 1][parent[k - 1][n]];
		}
	}
	cin >> M;
	for (num i = 0; i < M; i++) {
		num a, b;
		cin >> a >> b;
		cout << excuteLCA(a, b) << "\n";
	}

}

void BFS(num start) {
	queue<num> q;
	visited[start] = true;
	q.push(start);
	num level = 1;
	num now_size = 1;
	num count = 0;
	while (!q.empty()) {
		num now = q.front();
		q.pop();
		for (num next : tree[now]) {
			if (visited[next]) continue;
			q.push(next);
			visited[next] = true;
			parent[0][next] = now;
			depth[next] = level;
		}
		count++;
		if (count == now_size) { // level 깊이의 모든 노드를 탐색 했을 때,
			count = 0;
			now_size = q.size(); // 현재 큐의 사이즈는 다음 깊이의 노드 수
			level++;
		}
	}
}

num excuteLCA(num a, num b) {
	if (depth[a] > depth[b]) { // b를 깊이가 깊은 노드로 스왑
		num temp = a;
		a = b;
		b = temp;
	}
	for (num k = kmax; k >= 0; k--) {
		if (pow(2, k) <= depth[b] - depth[a]) {
			if (depth[a] <= depth[parent[k][b]]) {
				b = parent[k][b];
			}
		}
	}
	for (num k = kmax; k >= 0 && a != b; k--) {
		if (parent[k][a] != parent[k][b]) {
			a = parent[k][a];
			b = parent[k][b];
		}
	}
	num LCA = a;
	if (a != b)
		LCA = parent[0][LCA];
	return LCA;
}