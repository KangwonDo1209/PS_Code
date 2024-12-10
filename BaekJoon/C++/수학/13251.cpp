#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long num;

num M, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> M;
	vector<num> stones(M);
	num N = 0;
	for (num i = 0; i < M; i++) {
		cin >> stones[i];
		N += stones[i];
	}
	cin >> K;
	double ans = 0.0;
	// 각 조약돌마다 확률을 구해서 더함
	for (num i = 0; i < M; i++) {
		double a = N;
		double p = 1;
		double s = stones[i];
		for (num i = 0; i < K; i++) {
			p *= s-- / a--;
		}
		ans += p;
	}

	cout.precision(15);
	cout << ans;
}