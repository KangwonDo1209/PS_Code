#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long num;

struct reservation {
	num s, e;
	bool operator<(const reservation& temp) {
		if (e == temp.e)
			return s < temp.s;
		return e < temp.e;
	}
};

num N;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N;
	vector<reservation> res;
	res.resize(N);
	for (num i = 0; i < N; i++) {
		num a, b;
		cin >> a >> b;
		res[i] = reservation(a, b);
	}
	sort(res.begin(), res.end());
	num last = 0;
	num count = 0;
	for (num i = 0; i < N; i++) {
		reservation now = res[i];
		if (last <= now.s) {
			count++;
			last = now.e;
		}
	}
	cout << count;
}
