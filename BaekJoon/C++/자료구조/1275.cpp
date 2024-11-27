#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long num;

num N, Q;
vector<num> tree;

num getSum(num s, num e);
void setTree(num i);
void changeVal(num index, num val);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> Q;
	num treeHeight = 0;
	num length = N;
	while (length != 0) {
		length /= 2;
		treeHeight++;
	}
	num treeSize = num(pow(2, treeHeight + 1));
	num leftNodeStartIndex = treeSize / 2 - 1;
	tree.resize(treeSize + 1);
	for (num i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++) {
		cin >> tree[i];
	}
	setTree(treeSize);
	for (num i = 0; i < Q; i++) {
		num x, y, a, b;
		cin >> x >> y >> a >> b;
		num _x = min(x, y) + leftNodeStartIndex;
		num _y = max(x, y) + leftNodeStartIndex;
		a += leftNodeStartIndex;
		cout << getSum(_x, _y) << "\n";
		changeVal(a, b);
	}
}

num getSum(num s, num e) {
	num ans = 0;
	while (s <= e) {
		if (s % 2 == 1) {
			ans += tree[s];
			s++;
		}
		if (e % 2 == 0) {
			ans += tree[e];
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return ans;
}
void setTree(num i) {
	while (i > 0) {
		tree[i / 2] += tree[i];
		i--;
	}
}
void changeVal(num index, num val) {
	num diff = val - tree[index];
	while (index > 0) {
		tree[index] += diff;
		index /= 2;
	}
}