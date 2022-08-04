#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	int n, d, c, cost[10001];
	vector<vector<pair<int, int>>> com(10001);
	queue<pair<int, int>> q;

	cin >> n >> d >> c;

	for (int i = 0; i < d; i++) {
		int a, b, s;
		cin >> a >> b >> s;
		com[b].push_back({ a, s });
	}

	fill(cost, cost + 10001, int(1e9));
	cost[c] = 0;
	q.push({ 0, c });

	while (!q.empty()) {
		int d = q.front().first;
		int curr = q.front().second;

		q.pop();

		if (cost[curr] < d) continue;

		for (int i = 0; i < com[curr].size(); i++) {
			if (cost[com[curr][i].first] <= d + com[curr][i].second) continue;
			cost[com[curr][i].first] = com[curr][i].second + d;
			q.push({ cost[com[curr][i].first], com[curr][i].first });
		}
	}

	/*for (int i = 1; i <= n; i++)
		cout << cost[i] << '\t';
	cout << '\n';*/

	int count = 0, time = 0;
	for (int i = 1; i <= n; i++) {
		if (cost[i] >= 1e9) continue;
		count++;
		time = max(time, cost[i]);
	}

	cout << count << ' ' << time << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	
	while (t--)
		solve();

	return 0;
}