#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;

int n, a[26] = { 0, };
priority_queue<int> max_heap;

void solve() {
	int k = 0, num = 9;

	while (k != 26) {
		if (a[k] != 0) {
			max_heap.push(a[k]);
		}
		k++;
	}

	long long ans = 0;		
	while (!max_heap.empty()) {
		ans += max_heap.top() * num;
		max_heap.pop();
		--num;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		int k = 0, l = s.length();

		do {
			int idx = s[k++] - 65;
			a[idx] += pow(10, l - 1);
		} while (l--);
	}
	
	solve();

	return 0;
}