#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long num;

num N;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N;
	priority_queue<num, vector<num>, less<num>> p_pq;
	priority_queue<num, vector<num>, greater<num>> n_pq;
	for (num i = 0; i < N; i++) {
		num a;
		cin >> a;
		if (a > 0) p_pq.push(a);
		else n_pq.push(a);
	}
	num ans = 0;
	while (!p_pq.empty()) {
		num item = p_pq.top();
		p_pq.pop();
		if ((!p_pq.empty())) {
			num item2 = p_pq.top();
			p_pq.pop();
			if (item * item2 > item + item2)
				ans += item * item2;
			else
				ans += (item + item2);
		}
		else {
			ans += item;
		}
	}
	while (!n_pq.empty()) {
		num item = n_pq.top();
		n_pq.pop();
		if ((!n_pq.empty())) {
			num item2 = n_pq.top();
			n_pq.pop();
			ans += item * item2;
		}
		else {
			ans += item;
		}
	}
	cout << ans;
}
