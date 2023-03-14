#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int start, dst, sum[1001], fee[1001][1001];
vector<vector<int>> info(1001);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

void solve() {
	sum[start] = 0;
	min_heap.push({ sum[start], start });

	while (!min_heap.empty()) {
		int curr_city = min_heap.top().second;
		int curr_fee = min_heap.top().first;
		min_heap.pop();

		for (int i = 0; i < info[curr_city].size(); i++) {
			int next_city = info[curr_city][i];

			if (sum[next_city] <= curr_fee + fee[curr_city][next_city]) continue;

			sum[next_city] = curr_fee + fee[curr_city][next_city];
			min_heap.push({ sum[next_city],  next_city });
		}
	}
	cout << sum[dst] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, a, b, c;
	
	cin >> n >> m;

	memset(fee, -1, sizeof(fee));

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		info[a].push_back(b);

		if (fee[a][b] == -1) fee[a][b] = c;
		else {
			if (fee[a][b] > c) fee[a][b] = c;
		}
	}
	cin >> start >> dst;

	for (int i = 1; i <= n; i++)
		sum[i] = 1e9;
	
	solve();

	return 0;
}