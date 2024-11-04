#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long num;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	num N, C, x;
	cin >> N >> C;
	vector<num> X(N);
	for (num i = 0; i < N; i++) {
		cin >> x;
		X[i] = x;
	}
	sort(X.begin(), X.end());
	num s, e, m, ans;
	s = 1;
	e = X[N - 1] - X[0];
	ans = 0;
	while (s <= e) {
		m = (s + e) / 2;

		num cnt = 1;
		num prev_house = X[0];
		for (num i = 1; i < N; i++) {
			if (X[i] - prev_house >= m) {
				cnt++;
				prev_house = X[i];
			}
		}

		if (cnt >= C) {
			ans = max(ans, m);
			s = m + 1;
		}
		else {
			e = m - 1;
		}
	}
	cout << ans;
}