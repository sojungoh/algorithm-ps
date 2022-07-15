#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

priority_queue<long long> max_heap;

void solve() {
	vector<long long> ans;
	long long n, fibo, a[2] = {0, 1};
	cin >> n;

	do {
		fibo = a[0] + a[1];
		max_heap.push(fibo);
		a[0] = a[1];
		a[1] = fibo;
	} while (a[0] + a[1] <= n);

	while (!max_heap.empty()) {
		if (n == 0)
			break;
		if (max_heap.top() <= n) {
			n -= max_heap.top();
			ans.push_back(max_heap.top());
		}
		max_heap.pop();
	}

	auto i = ans.rbegin();
	while (i != ans.rend()) {
		cout << *i << ' ';
		++i;
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
		solve();

	return 0;
}