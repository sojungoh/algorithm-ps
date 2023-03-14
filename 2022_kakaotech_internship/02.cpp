#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

	int length = queue1.size();
	long long sum1 = 0, sum2 = 0;
	queue<int> q1, q2;

	for (int i = 0; i < queue1.size(); i++) {
		sum1 += queue1[i];
		sum2 += queue2[i];
		q1.push(queue1[i]);
		q2.push(queue2[i]);
	}

	if ((sum1 + sum2) % 2 == 1)
		return -1;

	while (!q1.empty() && !q2.empty()) {
		if (sum1 == sum2)
			break;

		if (answer >= 4 * length)
			break;

		if (sum1 > sum2) {
			sum1 -= q1.front();
			sum2 += q1.front();
			q2.push(q1.front());
			q1.pop();
		}
		else {
			sum2 -= q2.front();
			sum1 += q2.front();
			q1.push(q2.front());
			q2.pop();
		}
		answer += 1;
	}

	if (q1.empty() || q2.empty() || answer >= 4 * length)
		answer = -1;
    return answer;
}

//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//
//	vector<int> queue1 = { 1, 2, 1, 2 };
//	vector<int> queue2 = { 1, 10, 1, 2 };
//
//	cout << solution(queue1, queue2) << '\n';
//
//	return 0;
//}