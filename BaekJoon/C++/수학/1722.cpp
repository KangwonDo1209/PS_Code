#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long num;

num N, Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> Q;
	vector<num> F(N + 1);
	F[0] = 1;
	for (num i = 1; i <= N; i++) {
		F[i] = F[i - 1] * i;
	}

	if (Q == 1) {
		num k;
		cin >> k;
		vector<bool> visited(N + 1, false);
		k--;
		num a = k;
		num d = N - 1;
		vector<num> ans(N);
		for (num i = 0; i < N; i++) {
			num s = a / F[d];
			a = a % F[d];
			d--;
			num item;
			num c = 0;
			for (num j = 1; j <= N; j++) {
				if (visited[j]) continue;
				if (c == s) {
					item = j;
					visited[j] = true;
					break;
				}
				c++;
			}
			ans[i] = item;
		}
		for (num i = 0; i < N; i++) {
			cout << ans[i] << " ";
		}
	}
	else if (Q == 2) {
		vector<bool> visited(N + 1, false);
		vector<num> P(N + 1);
		num k = 1;
		for (num i = 1; i <= N; i++) {
			cin >> P[i];
			num cnt = 0;
			for (num j = 1; j < P[i]; j++) {
				if (!visited[j]) cnt++;
			}
			k += cnt * F[N - i];
			visited[P[i]] = true;
		}
		cout << k;
	}


}