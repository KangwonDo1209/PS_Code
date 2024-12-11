#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long num;

num N, M, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M >> K;
	num A[201][201];
	for (num i = 0; i <= N + M; i++) {
		A[i][1] = i;
		A[i][0] = 1;
		A[i][i] = 1;
	}
	for (num i = 2; i <= N + M; i++) {
		for (num j = 1; j < i; j++) {
			A[i][j] = A[i - 1][j] + A[i - 1][j - 1];
			if (A[i][j] > 1000000000)
				A[i][j] = 1000000001;
		}
	}
	if (A[N + M][M] < K) {
		cout << -1;
	}
	else {
		while (N > 0 || M > 0) { // a와 z가 모두 사용될 때까지
			// 첫 문자부터 순차적으로 선택하는 과정
			if (A[N - 1 + M][M] >= K) {
				// a를 선택할때, 남은 문자로 만들 수 있는 경우의 수가 K보다 크다면
				// K번째 경우의 수까지 선택해도 선택한 a가 z로 넘어가지 않으므로 a 확정
				cout << "a";
				N--;
			}
			else {
				// z를 선택할때, 남은 문자로 만들 수 있는 경우의 수가 K보다 작다면
				// K번째 경우의 수까지 선택하고 z로 넘어오므로, z 확정
				cout << "z";
				// A[N-1+M][M]만큼 a의 경우에 소비되므로 뺌.
				K -= A[N - 1 + M][M];
				M--;
			}
		}
	}


}