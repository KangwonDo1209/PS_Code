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
	// �Էº�
	cin >> N >> M;
	for (num i = 0; i < N; i++) {
		for (num j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	// �� �з�
	for (num i = 0; i < N; i++) {
		for (num j = 0; j < M; j++) {
			if (map[i][j] && !visited[i][j]) {
				BFS(i, j);
				sNum++;
				sumlist.push_back(mlist); // mlist���� BFS�� ���� ��� ���� ��ǥ�� ����
			}
		}
	}
	// ���� �� �������� ���� �� �ִ� ��� ���� ����
	for (num i = 0; i < sumlist.size(); i++) {
		vector<pair<num, num>> now = sumlist[i]; //���� ��
		num now_S = map[now[0].first][now[0].second]; // ���� �� ��ȣ
		for (num j = 0; j < now.size(); j++) {
			num r = now[j].first;
			num c = now[j].second;
			// �� �������� �ٸ� ���� ���ɼ� Ȯ��
			for (num d = 0; d < 4; d++) {
				num tempR = dr[d];
				num tempC = dc[d];
				num blength = 0;
				// ������ ��迡 �����ϸ� ����
				while (r + tempR >= 0 && r + tempR < N && c + tempC >= 0 && c + tempC < M) {
					if (map[r + tempR][c + tempC] == now_S) // �ش� ���⿡ ���� ���� ����
						break;
					else if (map[r + tempR][c + tempC] != 0) { // �ش� ���⿡ �ٸ� ���� ����
						if (blength > 1) // �ٸ��� ���̰� 2 �̻��̸� ���� ��Ͽ� �߰�
							pq.push(Edge{ now_S,map[r + tempR][c + tempC],blength });
						break;
					}
					else // �ش� ������ �ٴ��϶�
						blength++;
					// ���� �������� ����
					if (tempR < 0) tempR--;
					else if (tempR > 0) tempR++;
					else if (tempC < 0) tempC--;
					else if (tempC > 0) tempC++;
				}
			}
		}
	}
	// �θ� �迭 �ʱ�ȭ
	parent.resize(sNum);
	for (num i = 0; i < parent.size(); i++) {
		parent[i] = i;
	}
	// ũ�罺Į �˰���
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