﻿#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long num;

num N, M;
vector<num> tree;

num getSum(num s, num e);
void changeVal(num index, num val);

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
	fill(tree.begin(), tree.end(), 0);

	for (num i = 0; i < M; i++) {
		num a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			changeVal(b + leftNodeStartIndex, c);
		}
		else if (a == 0) {
			num s = min(b, c);
			num e = max(b, c);
			cout << getSum(s + leftNodeStartIndex, e + leftNodeStartIndex) << "\n";
		}
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
void changeVal(num index, num val) {
	num dff = val - tree[index];
	while (index > 0) {
		tree[index] += dff;
		index = index / 2;
	}
}

