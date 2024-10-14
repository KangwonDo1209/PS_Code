#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef  long long num;

/*
	ȯ���� �켱���� �� ���� �ð��� ���� ȯ���� ������ ����ؾ��Ѵ�.
	�̶�, ���� �� ���� �켱������ �ƹ��� �����ٰ� �ص�, ���� ġ�� ���� �ƴ� ���¿��� ȯ�ڰ� ���� �����Ѵٸ�,
	�� ȯ�ڰ� ���� ġ�Ḧ �ް� �ȴ�. �켱������ �ƹ��� ���Ƶ�, ġ�Ḧ �ߴܽ�ų ���� ���� �����̴�.
	����, �켱���� ť�� Ȱ���Ͽ� ġ�� ������ ����ϵ�, ���� �ð��� �������� ���� �������� ���� ���� ���ܽ�Ų��.

	�켱���� ť�� Ȱ���ϹǷ�, n log(n) �� �ð� ���⵵�� ������.
*/

struct customer {
	num priority;
	num arrive_time;
	num treatment_time;
	num index;
	customer(num p, num a, num t, num i) : priority(p), arrive_time(a), treatment_time(t), index(i) {};
};

struct compare {
	bool operator()(customer o1, customer o2) {
		if (o1.priority == o2.priority)
			return o1.arrive_time > o2.arrive_time;
		else
			return o1.priority > o2.priority;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	// �Է� �� ���ú�
	num n;
	cin >> n;
	priority_queue<customer, vector<customer>, compare> pq;

	for (num i = 0; i < n; i++) {
		num p, a, t;
		cin >> p >> a >> t;
		pq.push(customer(p, a, t, i));
	}

	vector<num> result(n);
	num current_time = 0;
	// ��� ȯ�ڰ� ��ġ �� ������ �ݺ�
	while (!pq.empty()) {
		queue<customer> q; // ���� �������� ���� ����� �ӽ÷� �����ϴ� ť
		while (pq.top().arrive_time > current_time) {
			// ���� �ð����� �ʰ� ������ ������ ������� q�� �ӽ� ����
			q.push(pq.top());
			pq.pop();
		}
		// �� �ܰ迡���� pq.top()�� ���� �ð��� ������ ������, �켱���� �� �����ð��� ��������, ���� ġ�� ���� ������ ���� ����̴�.
		result[pq.top().index] = current_time;
		current_time += pq.top().treatment_time;
		pq.pop();

		// ���� �������� ���� ������� �ٽ� pq�� ����
		while (!q.empty()) {
			pq.push(q.front());
			q.pop();
		}
	}

	// ��� ���
	for (num i = 0; i < n; i++) {
		cout << result[i] << "\n";
	}

}