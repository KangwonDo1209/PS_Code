#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef int num;
bool compare(num i, num j) {
	return i > j;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	num N, M;
	cin >> N >> M;
	vector<num> left; // 좌측 
	vector<num> right; // 우측
	num max = 0; // 최대 지점 거리
	while (N--) {
		num i;
		cin >> i;
		if (i > 0) right.push_back(i); // 우측
		else left.push_back(-i); // 좌측
		if (abs(i) > max)
			max = abs(i);
	}
	sort(left.begin(), left.end(), compare); // 좌측 내림차순 정렬
	sort(right.begin(), right.end(), compare); // 우측 내림차순 정렬
	num ans = 0;
	for (num i = 0; i < left.size(); i += M) { // 좌측 걸음 수 계산
		ans += left[i] * 2;
	}
	for (num i = 0; i < right.size(); i += M) { // 좌측 걸음 수 계산
		ans += right[i] * 2;
	}
	cout << ans - max; // 최대 지점은 마지막에 방문하여 돌아오지 않음
}