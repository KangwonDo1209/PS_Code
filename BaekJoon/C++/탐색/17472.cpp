#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;
typedef struct Edge {
	num s, e, v;
	bool operator> (const Edge& temp) const {
		return v > temp.v;
	}
};
num N, M, sNum;
vector<num> parent;
num dr[] = { -1,0,1,0 };
num dc[] = { 0,1,0,-1 };
num map[10][10];
bool visited[10][10] = { false, };
vector < vector<pair<num, num>>> sumlist;
vector<pair<num, num>> mlist;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

void unionfunc(num a, num b);
num find(num a);
void BFS(num i, num j);

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	sNum = 1;
	// 입력부
	cin >> N >> M;
	for (num i = 0; i < N; i++) {
		for (num j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	// 섬 분류
	for (num i = 0; i < N; i++) {
		for (num j = 0; j < M; j++) {
			if (map[i][j] && !visited[i][j]) {
				BFS(i, j);
				sNum++;
				sumlist.push_back(mlist); // mlist에는 BFS로 얻은 모든 섬의 좌표가 존재
			}
		}
	}
	// 섬의 각 지점에서 만들 수 있는 모든 간선 저장
	for (num i = 0; i < sumlist.size(); i++) {
		vector<pair<num, num>> now = sumlist[i]; //현재 섬
		num now_S = map[now[0].first][now[0].second]; // 현재 섬 번호
		for (num j = 0; j < now.size(); j++) {
			num r = now[j].first;
			num c = now[j].second;
			// 각 방향으로 다리 생성 가능성 확인
			for (num d = 0; d < 4; d++) {
				num tempR = dr[d];
				num tempC = dc[d];
				num blength = 0;
				// 월드의 경계에 도달하면 종료
				while (r + tempR >= 0 && r + tempR < N && c + tempC >= 0 && c + tempC < M) {
					if (map[r + tempR][c + tempC] == now_S) // 해당 방향에 같은 섬이 존재
						break;
					else if (map[r + tempR][c + tempC] != 0) { // 해당 방향에 다른 섬이 존재
						if (blength > 1) // 다리의 길이가 2 이상이면 간선 목록에 추가
							pq.push(Edge{ now_S,map[r + tempR][c + tempC],blength });
						break;
					}
					else // 해당 방향이 바다일때
						blength++;
					// 진행 방향으로 전진
					if (tempR < 0) tempR--;
					else if (tempR > 0) tempR++;
					else if (tempC < 0) tempC--;
					else if (tempC > 0) tempC++;
				}
			}
		}
	}
	// 부모 배열 초기화
	parent.resize(sNum);
	for (num i = 0; i < parent.size(); i++) {
		parent[i] = i;
	}
	// 크루스칼 알고리즘
	num useEdge = 0;
	num ans = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		if (find(now.s) != find(now.e)) {
			unionfunc(now.s, now.e);
			ans += now.v;
			useEdge++;
		}
	}
	if (useEdge == sNum - 2)
		cout << ans;
	else
		cout << -1;
}

void unionfunc(num a, num b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[b] = a;
}
num find(num a) {
	if (a == parent[a])  return a;
	else return parent[a] = find(parent[a]);
}
void BFS(num i, num j) {
	queue<pair<num, num>> q;
	mlist.clear();
	q.push(pair(i, j));
	mlist.push_back(pair(i, j));
	visited[i][j] = true;
	map[i][j] = sNum;
	while (!q.empty()) {
		num r = q.front().first;
		num c = q.front().second;
		q.pop();
		for (num d = 0; d < 4; d++) {
			num tempR = dr[d];
			num tempC = dc[d];
			while (r + tempR >= 0 && r + tempR < N && c + tempC >= 0 && c + tempC < M) {
				if (!visited[r + tempR][c + tempC] && map[r + tempR][c + tempC]) {
					num now_i = r + tempR;
					num now_j = c + tempC;
					map[now_i][now_j] = sNum;
					visited[now_i][now_j] = true;
					mlist.push_back(pair(now_i, now_j));
					q.push(pair(now_i, now_j));
				}
				else break;
				if (tempR < 0) tempR--;
				else if (tempR > 0) tempR++;
				else if (tempC < 0) tempC--;
				else if (tempC > 0) tempC++;
			}
		}
	}
}