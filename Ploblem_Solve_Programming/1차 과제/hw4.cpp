#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef int num;

/*
	�� �������� �ʿ��� �˰����� �� �����̴�.
	1. �����佺�׳׽��� ü
	2. ��Ŭ���� ȣ����
	�Ҽ� ������ ���, �ڸ����� ���� �ִ� ���� 50���� �����Ƿ�, �ð� ���⵵�� �ƹ� ū ������ ����.
	�ð� ���⵵�� ���� ū ������ ��ġ�� ��Ҵ� k�� �����̴�.
	k�� ���� ���� ��� k = n�� �� �� �����Ƿ�, �ð� ���⵵�� O(n^2) �̶�� �� �� �ִ�.
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

	// �Է� �� ���ú�
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