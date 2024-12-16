#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;

vector<num> parent;
num N;

void _union(num a, num b);
num _find(num a);
bool _check(num a, num b);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N;
	parent.resize(N + 1);
	for (num i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (num i = 0; i < N - 2; i++) {
		num a, b;
		cin >> a >> b;
		_union(a, b);
	}

	// ���� ���������� ������ �� ���� �������� ������.
	// 1�� ���� � ������ ���� ���� ���̴�.
	// 1�� ���� ���� ������ ������ ���� ������ �����ϸ� ��� ���� ����ȴ�.
	num s = 1;
	num e;
	for (num i = 2; i <= N; i++) {
		if (_find(s) != _find(i))
			e = i;
	}
	cout << s << " " << e;
}

void _union(num a, num b) {
	num ap = _find(a);
	num bp = _find(b);
	if (ap != bp) parent[bp] = ap;
}
num _find(num a) {
	if (a == parent[a]) return a;
	else return parent[a] = _find(parent[a]);
}
bool _check(num a, num b) {
	num ap = _find(a);
	num bp = _find(b);
	return ap == bp;
}
