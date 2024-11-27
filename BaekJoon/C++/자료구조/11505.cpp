#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long num;

num D = 1000000007;
num N, M, K;
vector<num> tree;

num getMul(num s, num e);
void changeVal(num index, num val);
void setTree(num i);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M >> K;
	num treeHeight = 0;
	num length = N;
	while (length != 0) {
		length /= 2;
		treeHeight++;
	}
	num treeSize = num(pow(2, treeHeight + 1));
	num leftNodeStartIndex = treeSize / 2 - 1;
	tree.resize(treeSize + 1);
	fill(tree.begin(), tree.end(), 1);
	for (num i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++) {
		cin >> tree[i];
	}
	setTree(treeSize - 1);
	for (num i = 0; i < M + K; i++) {
		num a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			changeVal(b + leftNodeStartIndex, c);
		}
		else if (a == 2) {
			cout << getMul(b + leftNodeStartIndex, c + leftNodeStartIndex) << "\n";
		}
	}
}
num getMul(num s, num e) {
	num ans = 1;
	while (s <= e) {
		if (s % 2 == 1) {
			ans = (ans * tree[s]) % D;
			s++;
		}
		if (e % 2 == 0) {
			ans = (ans * tree[e]) % D;
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return ans;
}
void changeVal(num index, num val) {
	tree[index] = val;
	while (index > 1) {
		index = index / 2;
		tree[index] = tree[index * 2] % D * tree[index * 2 + 1] % D;
	}
}
void setTree(num i) {
	while (i != 1) {
		tree[i / 2] = (tree[i / 2] * tree[i]) % D;
		i--;
	}
}
