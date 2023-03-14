#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define pii pair<int, int>

using namespace std;

int n;
vector<pii> due;
priority_queue<int> max_heap;

bool cmp(const pii& a, const pii& b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}

void solve() {
	long long ans = 0, date = due[0].first;

	for (int i = 0; i < due.size(); i++) {
		if (due[i].first < date) {
			for (int j = 0; j < date - due[i].first; j++) {
				if (!max_heap.empty()) {
					ans += max_heap.top();
					max_heap.pop();
				}
			}
			date = due[i].first;
		}
		max_heap.push(due[i].second);
	}

	for (int j = 0; j < date; j++) {
		if (!max_heap.empty()) {
			ans += max_heap.top();
			max_heap.pop();
		}
	}
	
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int d, w;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		due.push_back(pii(d, w));
	}
	sort(due.begin(), due.end(), cmp);

	solve();

	return 0;
}
