#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef  long long num;

/*
	이 알고리즘은 parametric search 알고리즘을 사용한다.
	H는 각 나무의 높이, max(H)는 나무의 높이 중 가장 큰 값을 의미한다.
	이진 탐색을 0~max(H)의 범위에서 진행하며, 각 탐색마다 0~n-1의 for문이 진행된다.
	따라서, O( n log(max(H)) ) 의 시간 복잡도를 가진다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	// 입력 + 세팅부
	num n, m;
	cin >> n >> m;
	vector<num> vec(n);

	num start = 0;
	num end = 0;
	for (num i = 0; i < n; i++) {
		cin >> vec[i];
		if (end < vec[i]) // 이진 탐색의 end를 가장 큰 나무의 높이로 설정
			end = vec[i];
	}

	// 탐색 시작 (parametric search)
	num result = 0;
	while (start <= end) {
		num mid = (start + end) / 2;
		num sum = 0;
		for (num i = 0; i < n; i++)
			sum += max(vec[i] - mid, (num)0);

		if (sum >= m) {
			start = mid + 1;
			result = mid;
		}
		else
			end = mid - 1;
	}
	cout << result;

}