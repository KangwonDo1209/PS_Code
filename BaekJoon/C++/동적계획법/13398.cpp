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
	vector<num> A(N);
	for (num i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<num> DP1(N);
	vector<num> DP2(N);
	DP1[0] = A[0];
	DP2[0] = A[0];
	num ans = A[0];
	for (num i = 1; i < N; i++) {
		DP1[i] = max(DP1[i - 1] + A[i], A[i]);
		DP2[i] = max(DP1[i - 1], DP2[i - 1] + A[i]);
		ans = max(ans, max(DP1[i], DP2[i]));
	}
	cout << ans;
}
