#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long num;

num N;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	num T;
	cin >> T;
	while (T--) {
		cin >> N;
		priority_queue<num, vector<num>, greater<num>> pq;

		for (num i = 0; i < N; i++) {
			num t;
			cin >> t;
			pq.push(t);
		}
		num ans = 0;
		for (num i = 0; i < N - 1; i++) {
			num a = pq.top();
			pq.pop();
			num b = pq.top();
			pq.pop();
			num c = a + b;
			ans += c;
			pq.push(c);
		}
		cout << ans << "\n";
	}
}
