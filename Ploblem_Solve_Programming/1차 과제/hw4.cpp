#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef int num;

/*
	이 문제에서 필요한 알고리즘은 두 가지이다.
	1. 에라토스테네스의 체
	2. 유클리드 호제법
	소수 판정의 경우, 자리수의 합의 최대 값이 50보자 작으므로, 시간 복잡도에 아무 큰 영향이 없다.
	시간 복잡도에 가장 큰 영향을 미치는 요소는 k의 개수이다.
	k가 가장 많은 경우 k = n이 될 수 있으므로, 시간 복잡도는 O(n^2) 이라고 할 수 있다.
*/

num n, input, k;
vector<bool> isprime(51, 1);
vector<num> vec;

bool isvalid(num k) {
	num sum = 0;
	while (k) {
		sum += (k % 10);
		k /= 10;
	}
	return isprime[sum];
}

num gcd(num a, num b) {
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

void eratos() {

	for (num i = 2; i * i <= 50; i++)
	{
		if (!isprime[i]) continue;
		for (num j = 2 * i; j <= 50; j += i) {
			isprime[j] = false;
		}
	}
	isprime[0] = false;
	isprime[1] = false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	// 입력 및 세팅부
	cin >> n;
	eratos();
	vec = vector<num>(n, 0);
	k = 0;
	for (num i = 0; i < n; i++) {
		cin >> input;
		if (isvalid(input)) {
			vec[k++] = input;
		}
	}
	num maxgcd = 0;
	for (num i = 0; i < k - 1; i++) {
		for (num j = i + 1; j < k; j++) {
			num g = gcd(vec[i], vec[j]);
			if (maxgcd < g)
				maxgcd = g;
		}
	}
	if (k < 2) cout << -1;
	else cout << maxgcd;

}