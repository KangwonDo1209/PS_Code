#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;
typedef int num;


/*
	�⺻���� solve �Լ��� �ڵ� ������ �̷���.
	1. ���ڿ��� <> ������ �и��Ͽ� vec�� �ִ´�.
	2. vec�� ����ҿ� ���������� �����Ͽ� ��ȿ�� �˻縦 �����Ѵ�.
		2-1. ���ڿ��� ������ �κ��� '/' �̶�� �� �±� �̹Ƿ� �����Ѵ�.
		2-2. <a href="#"></a> ���� href="#" ���� �κ��� �����ֱ� ���� ������ �������� ���ڿ��� �ɷ�����.
		2-3. �ɷ��� ���ڿ��� ù ���ڰ� '/'���� �ƴ����� ���� stack�� �̿��� ��ȿ�� �˻翡 ����.
				�� �κ��� ��ȣ ������ �����ϴ�. ���� ��ȿ���� ���ݵǴ� ����� ������ ��� "false"�� ��ȯ�ϰ� �����Ѵ�.
	3. ��ȿ�� �˻簡 ���� ���� ������ "true"�� ��ȯ�Ѵ�.


	�Է¹��� string�� ��� ��Ҹ� ��ȸ�ϴ� ���� �Ϲ����̹Ƿ�,
	�ð� ���⵵�� O(n) �̴�.
*/

size_t s, e;
string str;
stack<string> stk;
vector<string> vec;

string solve() {
	// ���ڿ� <> ������ �и�
	while ((s = str.find('<', e)) != string::npos) {
		e = str.find('>', s);
		if (e != string::npos)
			vec.push_back(str.substr(s + 1, e - s - 1));
	}
	// stack�� ���� ��ȿ�� ����
	for (string c : vec) {
		// �� �±� ����
		if (c[c.size() - 1] == '/')
			continue;

		// �±� �и�
		string sc;
		size_t spacePos = c.find(' ');
		if (spacePos != string::npos) {
			sc = c.substr(0, spacePos);
		}
		else {
			sc = c;
		}

		// ������ �̿��� �±� ��ȿ�� �˻�
		if (sc[0] != '/') stk.push(sc);
		else {
			if (stk.empty() || stk.top() != sc.substr(1)) return "false";
			stk.pop();
		}
	}
	return "true";
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	getline(cin, str);
	s = 0;
	e = 0;
	cout << solve();
}
