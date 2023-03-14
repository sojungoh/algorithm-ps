#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<long long> ans_v;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}

void solve() {
	int k, n;
	long long ans = 0;
	vector<pair<int, int>> price_map;
	vector<int> price;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k; 
		price.push_back(k);
	}

	for (int i = 0; i < n; i++) {
		price_map.push_back(make_pair(price[i], i));
	}

	sort(price_map.begin(), price_map.end(), cmp);

	int idx = -1;
	for (int i = 0; i < n; i++) {
		if (idx < price_map[i].second) {
			idx = price_map[i].second;
			min_heap.push(idx);
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (min_heap.empty())
			break;

		if (i < min_heap.top()) {
			ans += (price[min_heap.top()] - price[i]);
		}
		else
			min_heap.pop();
	}

	ans_v.push_back(ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
		solve();

	for (long long ans : ans_v)
		cout << ans << '\n';

	return 0;
}