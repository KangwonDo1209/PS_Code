#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long num;

/*
*	최대값 연산이 여러번 이루어지고, 추가도 빈번하므로 세그먼트 트리를 이용한다.
*	트리 초기화가 O(N), 한 번의 쿼리가 O(log(N)) 이므로,
*	시간 복잡도는 O(N+Qlog(N))이다.
*/

num N, Q;
vector<num> tree;

num getMax(num s, num e);
void setTree(num i);
void changeVal(num index, num val);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> Q;
	num treeSize = 1;
	num treedepth = 0;
	while (treeSize <= N) {
		treeSize *= 2;
		treedepth += 1;
	}
	treeSize *= 2;
	tree.resize(treeSize + 1);
	num leftStartIndex = pow(2, treedepth) - 1;
	for (num i = leftStartIndex + 1; i <= leftStartIndex + N; i++) {
		cin >> tree[i];
	}
	setTree(treeSize);
	for (num i = 0; i < Q; i++) {
		num a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			b += leftStartIndex;
			changeVal(b, c);
		}
		else if (a == 2) {
			b += leftStartIndex;
			c += leftStartIndex;
			cout << getMax(b, c) << "\n";
		}
	}

}

num getMax(num s, num e) {
	num ans = 0;
	while (s <= e) {
		if (s % 2 == 1) {
			ans = max(tree[s], ans);
			s++;
		}
		if (e % 2 == 0) {
			ans = max(tree[e], ans);
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return ans;
}
void setTree(num i) {
	while (i > 0) {
		tree[i / 2] = max(tree[i / 2], tree[i]);
		i--;
	}
}
void changeVal(num index, num val) {
	tree[index] = val;
	while (index > 0) {
		index /= 2;
		tree[index] = max(tree[index], val);
	}
}