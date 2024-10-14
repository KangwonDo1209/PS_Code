#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef  long long num;

/*
	환자의 우선순위 및 도착 시간에 따라 환자의 순서를 계산해야한다.
	이때, 주의 할 점은 우선순위가 아무리 빠르다고 해도, 먼저 치료 중이 아닌 상태에서 환자가 먼저 도착한다면,
	그 환자가 먼저 치료를 받게 된다. 우선순위가 아무리 높아도, 치료를 중단시킬 수는 없기 때문이다.
	따라서, 우선순위 큐를 활용하여 치료 순서를 계산하되, 현재 시간을 기준으로 아직 도착하지 않은 고객은 제외시킨다.

	우선순위 큐를 활용하므로, n log(n) 의 시간 복잡도를 가진다.
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

	// 입력 및 세팅부
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
	// 모든 환자가 배치 될 때까지 반복
	while (!pq.empty()) {
		queue<customer> q; // 아직 도착하지 않은 사람을 임시로 저장하는 큐
		while (pq.top().arrive_time > current_time) {
			// 현재 시간보다 늦게 도착할 예정인 사람들을 q에 임시 저장
			q.push(pq.top());
			pq.pop();
		}
		// 이 단계에서의 pq.top()은 현재 시간에 병원에 있으며, 우선순위 및 도착시간을 따졌을때, 가장 치료 받을 순서가 빠른 사람이다.
		result[pq.top().index] = current_time;
		current_time += pq.top().treatment_time;
		pq.pop();

		// 아직 도착하지 않은 사람들을 다시 pq에 삽입
		while (!q.empty()) {
			pq.push(q.front());
			q.pop();
		}
	}

	// 결과 출력
	for (num i = 0; i < n; i++) {
		cout << result[i] << "\n";
	}

}