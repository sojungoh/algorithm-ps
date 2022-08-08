#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int n, k, w, build_time[1001], indegree[1001] = { 0, };
vector<int> edges[1001];

void topology_sort() {
	queue<int> q;
	int ans[1001] = { 0, };

	for (int i = 1; i <= n; i++) {
		ans[i] = build_time[i];

		if (!indegree[i])
			q.push(i);
	}
	
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < edges[curr].size(); i++) {
			int next = edges[curr][i];
			ans[next] = max(ans[next], ans[curr] + build_time[next]);
			indegree[next] -= 1;

			if (!indegree[next]) q.push(next);
		}
	}

	cout << ans[w] << '\n';
}

void solve() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> build_time[i];

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		edges[x].push_back(y);
		indegree[y] += 1;
	}

	cin >> w;

	topology_sort();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
		memset(build_time, 0, sizeof(build_time));
		memset(indegree, 0, sizeof(indegree));
		for (int i = 1; i <= n; i++)
			edges[i].clear();
	}	

	return 0;
}