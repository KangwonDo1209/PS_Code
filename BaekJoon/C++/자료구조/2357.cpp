#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long num;
num lmax = 9999999999;
num lmin = 0;
num N, M;
vector<num> mintree;
vector<num> maxtree;

num getMin(num s, num e);
num getMax(num s, num e);
void setMinTree(num i);
void setMaxTree(num i);

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
	maxtree.resize(treeSize + 1);
	mintree.resize(treeSize + 1);
	fill(maxtree.begin(), maxtree.end(), lmin);
	fill(mintree.begin(), mintree.end(), lmax);
	for (num i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++) {
		num item;
		cin >> item;
		maxtree[i] = item;
		mintree[i] = item;
	}
	setMinTree(treeSize);
	setMaxTree(treeSize);
	for (num i = 0; i < M; i++) {
		num s, e;
		cin >> s >> e;
		s += leftNodeStartIndex;
		e += leftNodeStartIndex;
		cout << getMin(s, e) << " " << getMax(s, e) << "\n";
	}
}

num getMin(num s, num e) {
	num ans = lmax;
	while (s <= e) {
		if (s % 2 == 1) {
			ans = min(ans, mintree[s]);
			s++;
		}
		if (e % 2 == 0) {
			ans = min(ans, mintree[e]);
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return ans;
}
num getMax(num s, num e) {
	num ans = lmin;
	while (s <= e) {
		if (s % 2 == 1) {
			ans = max(ans, maxtree[s]);
			s++;
		}
		if (e % 2 == 0) {
			ans = max(ans, maxtree[e]);
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return ans;
}
void setMinTree(num i) {
	while (i > 0) {
		mintree[i / 2] = min(mintree[i / 2], mintree[i]);
		i--;
	}
}
void setMaxTree(num i) {
	while (i > 0) {
		maxtree[i / 2] = max(maxtree[i / 2], maxtree[i]);
		i--;
	}
}