#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef int num;
typedef pair<num, num> pool;

bool compare(pool a, pool b) {
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	num N, L;
	cin >> N >> L;
	vector<pool> pools;
	for (num i = 0; i < N; i++) {
		num a, b;
		cin >> a >> b;
		pools.push_back(pool(a, b));
	}
	sort(pools.begin(), pools.end(), compare);
	num ans = 0;
	num p = pools[0].first - 1; // 0~p 지점은 전부 보수됨.

	for (num i = 0; i < N; i++) {

		// p가 이미 덮인 판자면 생략
		if (p >= pools[i].second) continue;

		// 다음 판자의 시작지점
		// 현재 p가 다음 웅덩이보다 왼쪽에 있으면
		// next = 웅덩이의 시작지점
		// 아니면 next = p+1
		num next = (p < pools[i].first) ? pools[i].first : p + 1; 
		// 현재 덮어야하는 웅덩이 길이(이미 덮인 지점 제외)
		num len = pools[i].second - next;
		// 현재 웅덩이를 덮기위한 판자 개수 계산
		num q = len / L;
		if (len % L) q++;

		// 덮은 판자의 마지막 지점을 p로
		p = next + q * L - 1;

		ans += q;
	}
	cout << ans;
}