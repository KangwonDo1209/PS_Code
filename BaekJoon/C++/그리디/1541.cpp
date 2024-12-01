#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
typedef long long num;

vector<string> split(string input, char delimiters);
num _sum(string str);
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	string str;
	cin >> str;
	vector<string> strs = split(str, '-');
	num ans = 0;

	ans += _sum(strs[0]);
	for (num i = 1; i < strs.size(); i++) {
		ans -= _sum(strs[i]);
	}

	cout << ans;
}
vector<string> split(string input, char delimiters) {
	vector<string> vec;
	stringstream stream(input);
	string splitdata;
	while (getline(stream, splitdata, delimiters)) {
		vec.push_back(splitdata);
	}
	return vec;
}
num _sum(string str) {
	num sum = 0;
	vector<string> temp = split(str, '+');
	for (string s : temp) {
		sum += stoi(s);
	}
	return sum;
}