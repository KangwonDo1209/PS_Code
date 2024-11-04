#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long num;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	num N, x;
	cin >> N;
	vector<num> X(N);
	for (num i = 0; i < N; i++) {
		cin >> x;
		X[i] = x;
	}
	sort(X.begin(), X.end());
	num Rsum = 2000000001;
	num Rs = 0;
	num Re = 0;
	num s, e;
	s = 0;
	e = N - 1;
	while (s < e) {
		num vs = X[s];
		num ve = X[e];
		num sum = vs + ve;

		if (abs(sum) < abs(Rsum)) {
			Rsum = sum;
			Rs = vs;
			Re = ve;
		}

		if (sum == 0) break;
		else if (sum < 0) s++;
		else e--;
	}
	cout << Rs << " " << Re;
}