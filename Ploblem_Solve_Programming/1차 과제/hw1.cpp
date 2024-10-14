#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef  long long num;

/*
	�� �˰����� �Է°� �����̵� ������ ��� ��� O(n)�� �ð� ���⵵�� �����Ƿ�,
	�ð����⵵�� O(n)�̴�.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	// �Էº�
	num n, k;
	cin >> n;
	vector<num> vec(n);
	for (num i = 0; i < n; i++) {
		cin >> vec[i];
	}
	cin >> k;

	// �����̵� ������ �ʱ� ����
	num sum = 0;
	for (num i = 0; i < k; i++) {
		sum += vec[i];
	}

	// �����̵� �����츦 �̿��� ��� ���
	bool all_failed = true;
	for (num i = 0; i < n - k; i++) {
		if (sum % k == 0) {
			cout << (sum / k) << "\n";
			all_failed = false;
		}
		sum += (vec[i + k] - vec[i]);
	}
	if (sum % k == 0) {
		cout << (sum / k) << "\n";
		all_failed = false;
	}
	if (all_failed) cout << -1;
}