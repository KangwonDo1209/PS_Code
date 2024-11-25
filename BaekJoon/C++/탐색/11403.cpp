#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;

num lmax = 92233720368547580;
num matrix[101][101];

num N, M;

void floyd_warshall();

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N;
	for (num i = 1; i <= N; i++) {
		for (num j = 1; j <= N; j++) {
			num v;
			cin >> v;
			matrix[i][j] = (v == 1 ? 1 : lmax);
		}
	}
	floyd_warshall();
	for (num i = 1; i <= N; i++) {
		for (num j = 1; j <= N; j++) {
			cout << (matrix[i][j] == lmax ? 0 : 1) << " ";
		}
		cout << "\n";
	}
}
// 플로이드 워셜 알고리즘
void floyd_warshall() {
	for (num k = 1; k <= N; k++) {
		for (num i = 1; i <= N; i++) {
			for (num j = 1; j <= N; j++) {
				if (matrix[i][j] > matrix[i][k] + matrix[k][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
			}
		}
	}
}