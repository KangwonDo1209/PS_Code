#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long num;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	num T;
	cin >> T;
	while (T--) {
		num N;
		cin >> N;

		stack<num> stk;
		for (num i = 0; i < N; i++) {
			num a;
			cin >> a;
			stk.push(a);
		}
		num ans = 0;
		num mx = stk.top();
		while (!stk.empty()) {
			num cur = stk.top();
			stk.pop();
			if (cur < mx) ans += mx - cur;
			else mx = cur;
		}
		cout << ans << "\n";
	}

}
