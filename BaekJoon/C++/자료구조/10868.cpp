#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long num;
num lmax = 9999999999;

num N, M;
vector<num> tree;

num getMin(num s, num e);
void setTree(num i);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M;
	num treeHeight = 0;
	num length = N;
	while (length != 0) {
		length /= 2;
		treeHeight++;
	}
	num treeSize = num(pow(2, treeHeight + 1));
	num leftNodeStartIndex = treeSize / 2 - 1;
	tree.resize(treeSize + 1);
	fill(tree.begin(), tree.end(), lmax);
	for (num i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++) {
		num item;
		cin >> tree[i];
	}
	setTree(treeSize - 1);
	for (num i = 0; i < M; i++) {
		num s, e;
		cin >> s >> e;
		cout << getMin(s + leftNodeStartIndex, e + leftNodeStartIndex) << "\n";
	}
}
num getMin(num s, num e) {
	num ans = lmax;
	while (s <= e) {
		if (s % 2 == 1) {
			ans = min(ans, tree[s]);
			s++;
		}
		if (e % 2 == 0) {
			ans = min(ans, tree[e]);
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return ans;
}
void setTree(num i) {
	while (i != 1) {
		tree[i / 2] = min(tree[i / 2], tree[i]);
		i--;
	}
}
