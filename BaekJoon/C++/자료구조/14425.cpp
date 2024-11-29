#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
typedef long long num;

num N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M;
	string str;
	unordered_set<string> set;
	for (num i = 0; i < N; i++) {
		cin >> str;
		set.insert(str);
	}
	num ans = 0;
	for (num i = 0; i < M; i++) {
		cin >> str;
		ans += (set.contains(str) ? 1 : 0);
	}
	cout << ans;
}
