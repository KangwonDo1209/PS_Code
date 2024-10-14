#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef  long long num;

/*
	이 알고리즘은 입력과 슬라이딩 윈도우 계산 모두 O(n)의 시간 복잡도를 가지므로,
	시간복잡도가 O(n)이다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	// 입력부
	num n, k;
	cin >> n;
	vector<num> vec(n);
	for (num i = 0; i < n; i++) {
		cin >> vec[i];
	}
	cin >> k;

	// 슬라이딩 윈도우 초기 세팅
	num sum = 0;
	for (num i = 0; i < k; i++) {
		sum += vec[i];
	}

	// 슬라이딩 윈도우를 이용한 평균 계산
	bool all_failed = true;
	for (num i = 0; i < n - k; i++) {
		if (sum % k == 0) {
			cout << (sum / k) << "\n";
			all_failed = false;
		}
		sum += (vec[i + k] - vec[i]);
	}
	if (sum % k == 0) {
		cout << (sum / k) << "\n";
		all_failed = false;
	}
	if (all_failed) cout << -1;
}