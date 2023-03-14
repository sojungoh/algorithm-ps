#include <iostream>
#include <queue>

using namespace std;

int n, m, sum = 0;
priority_queue<int> min_heap;

void solve() {
	int max_cost = m / n, sub = m;

	while (!min_heap.empty()) {
		int cost = -min_heap.top();
		min_heap.pop();

		if (sum <= m) {
			max_cost = cost;
			continue;
		}

		if (sub <= 0) break;

		if (cost > max_cost) {
			int cmp = sub / (min_heap.size() + 1);
			max_cost = max(max_cost, cmp);
		}

		sub -= cost;
	}

	cout << max_cost << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		sum += k;
		min_heap.push(-k);
	}

	cin >> m;

	solve();

	return 0;
}