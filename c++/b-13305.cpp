#include <iostream>
#include <algorithm>
#include <vector>

#define pii pair<long long, int>

using namespace std;

int n;
vector<pii> price;
vector<long long> dist;

long long sum_dist(int start, int end) {
	long long sum = 0;

	for (int i = start - 1; i < end - 1; i++)
		sum += dist[i];

	return sum;
}

void solve() {
	int check = n;
	long long ans = 0;

	for (int i = 0; i < n; i++) {
		if (check <= price[i].second)
			continue;

		ans += price[i].first * sum_dist(price[i].second, check);
		check = price[i].second;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	long long value;
	for (int i = 0; i < n - 1; i++) {
		cin >> value;
		dist.push_back(value);
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> value;
		price.push_back(make_pair(value, i));
	}

	sort(price.begin(), price.end());

	solve();

	return 0;
}