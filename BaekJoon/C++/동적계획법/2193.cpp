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
	vector<num> A(N + 1);
	A[0] = 0;
	A[1] = 1;
	for (num i = 2; i <= N; i++) {
		A[i] = A[i - 1] + A[i - 2];
	}
	cout << A[N];
}