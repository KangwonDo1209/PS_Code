#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;
typedef int num;


/*
	기본적인 solve 함수의 코드 구성인 이렇다.
	1. 문자열을 <> 단위로 분리하여 vec에 넣는다.
	2. vec의 모든요소에 순차적으로 접근하여 유효성 검사를 진행한다.
		2-1. 문자열의 마지막 부분이 '/' 이라면 빈 태그 이므로 생략한다.
		2-2. <a href="#"></a> 에서 href="#" 같은 부분을 지워주기 위해 공백을 기준으로 문자열을 걸러낸다.
		2-3. 걸러낸 문자열의 첫 문자가 '/'인지 아닌지에 따라 stack을 이용한 유효성 검사에 들어간다.
				이 부분은 괄호 검증과 유사하다. 만약 유효성이 위반되는 결과가 나오면 즉시 "false"를 반환하고 종료한다.
	3. 유효성 검사가 문제 없이 끝나면 "true"를 반환한다.


	입력받은 string의 모든 요소를 순회하는 것이 일반적이므로,
	시간 복잡도는 O(n) 이다.
*/

size_t s, e;
string str;
stack<string> stk;
vector<string> vec;

string solve() {
	// 문자열 <> 단위로 분리
	while ((s = str.find('<', e)) != string::npos) {
		e = str.find('>', s);
		if (e != string::npos)
			vec.push_back(str.substr(s + 1, e - s - 1));
	}
	// stack을 통한 유효성 검증
	for (string c : vec) {
		// 빈 태그 생략
		if (c[c.size() - 1] == '/')
			continue;

		// 태그 분리
		string sc;
		size_t spacePos = c.find(' ');
		if (spacePos != string::npos) {
			sc = c.substr(0, spacePos);
		}
		else {
			sc = c;
		}

		// 스택을 이용한 태그 유효성 검사
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
