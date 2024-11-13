#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long num;

vector<num> tree;

num getSum(num s, num e);
void changeVal(num index, num val);
void setTree(num i);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	num n, m, k;
	cin >> n >> m >> k;
	num treeHeight = 0;
	num length = n;
	while (length != 0) {
		length /= 2;
		treeHeight++;
	}
	num treeSize = num(pow(2, treeHeight + 1));
	num leftNodeStartIndex = treeSize / 2 - 1;
	tree.resize(treeSize + 1);

	for (num i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + n; i++) {
		cin >> tree[i];
	}
	setTree(treeSize - 1);

	for (num i = 0; i < m + k; i++) {
		num a, s, e;
		cin >> a >> s >> e;
		if (a == 1) {
			changeVal(leftNodeStartIndex + s, e);
		}
		else if (a == 2) {
			s += leftNodeStartIndex;
			e += leftNodeStartIndex;
			cout << getSum(s, e) << "\n";
		}
	}
}

num getSum(num s, num e) {
	num partSum = 0;
	while (s <= e) {
		if (s % 2 == 1) {
			partSum += tree[s];
			s++;
		}
		if (e % 2 == 0) {
			partSum += tree[e];
			e--;
		}
		s = s / 2;
		e = e / 2;
	}
	return partSum;
}
void changeVal(num index, num val) {
	num diff = val - tree[index];
	while (index > 0) {
		tree[index] += diff;
		index /= 2;
	}
}
void setTree(num i) {
	while (i != 1) {
		tree[i / 2] += tree[i];
		i--;
	}
}
