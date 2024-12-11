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

	num A[10][101];
	A[0][1] = 0;
	for (num i = 1; i <= 9; i++) {
		A[i][1] = 1;
	}
	for (num i = 2; i <= N; i++) {
		for (num j = 0; j <= 9; j++) {
			num temp = 0;
			if (j - 1 >= 0) temp += A[j - 1][i - 1];
			if (j + 1 <= 9) temp += A[j + 1][i - 1];

			A[j][i] = temp % 1000000000;
		}
	}
	num sum = 0;
	for (num i = 0; i <= 9; i++) {
		sum += A[i][N] % 1000000000;
	}
	cout << sum % 1000000000;
}
