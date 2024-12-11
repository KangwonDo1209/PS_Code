#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long num;

num N;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> N;
	vector<num> A(N + 2, 0);
	vector<num> T(N + 1, 0);
	vector<num> P(N + 1, 0);
	for (num i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for (num i = N; i >= 1; i--) {
		if (i + T[i] > N + 1)
			A[i] = A[i + 1];
		else
			A[i] = max(A[i + 1], P[i] + A[i + T[i]]);
	}

	cout << A[1];
}