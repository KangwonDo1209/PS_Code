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
	vector<num> A(N * 3 + 1);
	A[1] = 0;
	for (num i = 2; i <= N; i++) {
		A[i] = 1000000000;
	}
	for (num i = 1; i <= N; i++) {
		A[i + 1] = min(A[i + 1], A[i] + 1);
		A[i * 2] = min(A[i * 2], A[i] + 1);
		A[i * 3] = min(A[i * 3], A[i] + 1);
	}
	cout << A[N];
}