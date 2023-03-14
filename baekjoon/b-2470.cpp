#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
priority_queue<pair<int, int>> min_heap;

void solve() {
	int ans[2] = { 0, }, min_cost = 2147483647;

	while (!min_heap.empty()) {
		int first = min_heap.top().second;
		min_heap.pop();

		if (min_heap.empty()) break;

		int second = min_heap.top().second;

		if (abs(min_cost) > abs(first + second)) {
			min_cost = first + second;
			ans[0] = first < second ? first : second;
			ans[1] = first < second ? second : first;
		}
	}

	cout << ans[0] << ' ' << ans[1] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;

		min_heap.push({ -abs(k), k });
	}

	solve();

	return 0;
}