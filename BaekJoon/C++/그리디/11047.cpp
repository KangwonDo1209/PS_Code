#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long num;

num N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> K;
	num ans = 0;
	vector<num> values(N);
	for (num i = 0; i < N; i++) {
		cin >> values[i];
	}
	for (num i = N - 1; i >= 0; i--) {
		ans += (K / values[i]);
		K %= values[i];
	}
	cout << ans;
}
