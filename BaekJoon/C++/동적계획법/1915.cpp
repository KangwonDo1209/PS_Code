#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long num;

num N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M;
	vector<vector<num>> A(N);
	for (num i = 0; i < N; i++) {
		A[i].resize(M);
		string sLine;
		cin >> sLine;
		for (num j = 0; j < M; j++) {
			A[i][j] = sLine[j] - '0';
		}
	}
	// A[i][j]�� �ش� ���� ������ �Ʒ� ���������� �ϴ� ���簢���� �ִ� ����
	num maxLen = 0;
	for (num i = 0; i < N; i++) {
		for (num j = 0; j < M; j++) {
			if (A[i][j] && i > 0 && j > 0)
				A[i][j] = min(A[i - 1][j - 1], min(A[i - 1][j], A[i][j - 1])) + 1;

			// �ִ� ���ϱ�
			if (maxLen < A[i][j])
				maxLen = A[i][j];
		}
	}
	cout << maxLen * maxLen;
}
