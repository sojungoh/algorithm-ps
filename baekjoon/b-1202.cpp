#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define pii pair<int, int>

using namespace std;

int n, k;
vector<pii> jewellery;
vector<int> bags;
priority_queue<int> max_heap;

bool cmp(pii& a, pii& b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

void solve() {
	int i = 0, j = 0;
	long long ans = 0;

	while (j != k) {
		if (i != n && bags[j] >= jewellery[i].first) {
			max_heap.push(jewellery[i].second);
			i++;
			continue;
		}

		if (!max_heap.empty()) {
			ans += max_heap.top();
			max_heap.pop();
		}
		++j;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	int mass, value;
	for (int i = 0; i < n; i++) {
		cin >> mass >> value;
		jewellery.push_back(pii(mass, value));
	}

	for (int i = 0; i < k; i++) {
		cin >> mass;
		bags.push_back(mass);
	}

	sort(jewellery.begin(), jewellery.end(), cmp);
	sort(bags.begin(), bags.end());

	solve();

	return 0;
}