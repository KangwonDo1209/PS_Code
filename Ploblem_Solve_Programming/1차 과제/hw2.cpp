#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef  long long num;

/*
	�� �˰����� parametric search �˰����� ����Ѵ�.
	H�� �� ������ ����, max(H)�� ������ ���� �� ���� ū ���� �ǹ��Ѵ�.
	���� Ž���� 0~max(H)�� �������� �����ϸ�, �� Ž������ 0~n-1�� for���� ����ȴ�.
	����, O( n log(max(H)) ) �� �ð� ���⵵�� ������.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	// �Է� + ���ú�
	num n, m;
	cin >> n >> m;
	vector<num> vec(n);

	num start = 0;
	num end = 0;
	for (num i = 0; i < n; i++) {
		cin >> vec[i];
		if (end < vec[i]) // ���� Ž���� end�� ���� ū ������ ���̷� ����
			end = vec[i];
	}

	// Ž�� ���� (parametric search)
	num result = 0;
	while (start <= end) {
		num mid = (start + end) / 2;
		num sum = 0;
		for (num i = 0; i < n; i++)
			sum += max(vec[i] - mid, (num)0);

		if (sum >= m) {
			start = mid + 1;
			result = mid;
		}
		else
			end = mid - 1;
	}
	cout << result;

}