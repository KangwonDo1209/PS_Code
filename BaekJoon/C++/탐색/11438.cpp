#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long num;
num N, M;
num kmax; // k가 가질 수 있는 최대값
vector<vector<num>> tree;
vector<num> depth;
num parent[21][100001]; // parent[k][i]는 i의 2^k 번째 조상
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
		temp <<= 1; // 2씩 곱함
		kmax++;
	}
	BFS(1);
	// BFS로 얻은 parent[0][k] (1<=k<=N)의 나머지 부분 채우기
	for (num k = 1; k <= kmax; k++) {
		for (num n = 1; n <= N; n++) {
			parent[k][n] = parent[k - 1][parent[k - 1][n]]; // 2^k번째 부모는 2^(k-1)번쨰 부모의 2^(k-1)번째 부모와 같음
		}
	}
	cin >> M;
	for (num i = 0; i < M; i++) {
		num a, b;
		cin >> a >> b;
		cout << excuteLCA(a, b) << "\n";
	}

}

/*
*	start 노드를 루트(깊이 1)로 하여, 모든 노드를 탐색
*	모든 노드의 깊이와 부모를 탐색
*/
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
/*
*	구한 parent를 이용하여, 빠르게 LCA 탐색
*/
num excuteLCA(num a, num b) {
	// b를 깊이가 깊은 노드로 스왑
	if (depth[a] > depth[b]) {
		num temp = a;
		a = b;
		b = temp;
	}
	for (num k = kmax; k >= 0; k--) { // a와 b의 조상노드로 거슬러가면서 깊이를 맞춰주기
		if (pow(2, k) <= depth[b] - depth[a]) {
			if (depth[a] <= depth[parent[k][b]]) {
				b = parent[k][b];
			}
		}
	}
	// 깊이는 맞추었지만, a와 b가 다르면 작동함
	for (num k = kmax; k >= 0 && a != b; k--) {
		if (parent[k][a] != parent[k][b]) { // 2^k번쨰 부모가 다르다면, 부모를 타고 올라감
			a = parent[k][a];
			b = parent[k][b];
		}
	}
	num LCA = a;
	if (a != b)
		LCA = parent[0][LCA];
	return LCA;
}