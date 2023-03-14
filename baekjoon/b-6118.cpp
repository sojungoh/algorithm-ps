#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, dist[20001], ans[3] = { 0, };
vector<vector<int>> place(20001);
priority_queue<pair<int, int>> min_heap;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		place[a].push_back(b);
		place[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		dist[i] = int(1e9);
	dist[1] = 0;

	min_heap.push({ 0, 1 });

	while (!min_heap.empty()) {
		int d = -min_heap.top().first;
		int num = min_heap.top().second;
		min_heap.pop();

		if (dist[num] < d) continue;

		for (int i = 0; i < place[num].size(); i++) {
			if (dist[place[num][i]] <= d + 1) continue;
			dist[place[num][i]] = d + 1;
			min_heap.push({ -dist[place[num][i]], place[num][i] });
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] >= 1e9) continue;

		if (ans[1] < dist[i]) {
			ans[1] = dist[i];
			ans[0] = i;
			ans[2] = 0;
		}
		if (ans[1] == dist[i])
			ans[2] += 1;
	}

	for (int i = 0; i < 3; i++)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}