#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;
num N, M;
vector<vector<num>> tree;
vector<num> parent;
vector<num> depth;
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
	parent.resize(N + 1);
	depth.resize(N + 1);
	fill(visited.begin(), visited.end(), false);
	for (num i = 0; i < N - 1; i++) {
		num a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	BFS(1);
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
			parent[next] = now;
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
	if (depth[a] < depth[b]) { // a를 깊이가 깊은 노드로 스왑
		num temp = a;
		a = b;
		b = temp;
	}
	while (depth[a] != depth[b]) { // a의 깊이가 b와 같아질 때까지 조상 탐색
		a = parent[a];
	}
	while (a != b) { // 같은 깊이에 도달해도 a와 b가 다르면, 같아질 때까지 조상 탐색
		a = parent[a];
		b = parent[b];
	}
	return a;
}