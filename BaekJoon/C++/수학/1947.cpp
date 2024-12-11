#include <iostream>
#include <algorithm>
#include <vector>
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
	A[1] = 0;
	A[2] = 1;
	for (num i = 3; i <= N; i++) {
		A[i] = (i - 1) * (A[i - 1] + A[i - 2]) % 1000000000;
	}
	cout << A[N];
}