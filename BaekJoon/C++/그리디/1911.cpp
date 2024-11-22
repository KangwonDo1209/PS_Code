#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef int num;
typedef pair<num, num> pool;

bool compare(pool a, pool b) {
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	num N, L;
	cin >> N >> L;
	vector<pool> pools;
	for (num i = 0; i < N; i++) {
		num a, b;
		cin >> a >> b;
		pools.push_back(pool(a, b));
	}
	sort(pools.begin(), pools.end(), compare);
	num ans = 0;
	num p = pools[0].first - 1; // 0~p ������ ���� ������.

	for (num i = 0; i < N; i++) {

		// p�� �̹� ���� ���ڸ� ����
		if (p >= pools[i].second) continue;

		// ���� ������ ��������
		// ���� p�� ���� �����̺��� ���ʿ� ������
		// next = �������� ��������
		// �ƴϸ� next = p+1
		num next = (p < pools[i].first) ? pools[i].first : p + 1; 
		// ���� ������ϴ� ������ ����(�̹� ���� ���� ����)
		num len = pools[i].second - next;
		// ���� �����̸� �������� ���� ���� ���
		num q = len / L;
		if (len % L) q++;

		// ���� ������ ������ ������ p��
		p = next + q * L - 1;

		ans += q;
	}
	cout << ans;
}