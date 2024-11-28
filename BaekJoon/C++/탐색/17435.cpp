#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long num;
num M, Q;
num f[21][200001];
num kmax;
num query(num n, num x);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> M;
	for (num i = 1; i <= M; i++) {
		cin >> f[0][i];
	}
	num temp = 1;
	kmax = 20;
	for (num k = 1; k <= kmax; k++) {
		for (num i = 1; i <= M; i++) {
			f[k][i] = f[k - 1][f[k - 1][i]];
		}
	}
	cin >> Q;
	for (num i = 0; i < Q; i++) {
		num n, x;
		cin >> n >> x;
		cout << query(n, x) << "\n";
	}
}

num query(num n, num x) {

	num t = 1;
	num k = 0;
	while (t < n) {
		t <<= 1;
		k++;
	}

	while (t > 0) {
		if (t & n) {
			x = f[k][x];
			n -= t;
		}
		t >>= 1;
		k--;
	}
	return x;
}