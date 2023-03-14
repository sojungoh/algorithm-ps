#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m, fox_dist[4001], wolf_dist[4001][2];
vector<vector<pair<int, int>>> map(4001);

void dijk_wolf() {
	priority_queue<tuple<int, int, int>> min_heap;

	fill(&wolf_dist[1][0], &wolf_dist[4000][2], int(1e9));

	wolf_dist[1][0] = 0;
	min_heap.push({ 0, 0, 1 });

	while (!min_heap.empty()) {
		int dist = -get<0>(min_heap.top());
		int depth = get<1>(min_heap.top()) + 1;
		int curr = get<2>(min_heap.top());
		min_heap.pop();

		if (wolf_dist[curr][(depth - 1) % 2] < dist) continue;

		for (int i = 0; i < map[curr].size(); i++) {
			int cost = (depth % 2 == 1) ? map[curr][i].second / 2 : map[curr][i].second * 2;

			if (wolf_dist[map[curr][i].first][depth % 2] <= cost + dist) continue;
			wolf_dist[map[curr][i].first][depth % 2] = cost + dist;
			min_heap.push({ -(cost + dist), depth, map[curr][i].first });
		}
	}
}

void dijk_fox() {
	priority_queue<pair<int, int>> min_heap;
	
	fill(fox_dist, fox_dist + 4001, int(1e9));
	
	fox_dist[1] = 0;
	min_heap.push({0, 1});

	while (!min_heap.empty()) {
		int d = -min_heap.top().first;
		int node = min_heap.top().second;
		min_heap.pop();

		if (fox_dist[node] < d) continue;

		for (int i = 0; i < map[node].size(); i++) {
			if (fox_dist[map[node][i].first] <= d + map[node][i].second) continue;
			fox_dist[map[node][i].first] = d + map[node][i].second;
			min_heap.push({ -fox_dist[map[node][i].first], map[node][i].first });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		map[a].push_back({ b, 2 * d });
		map[b].push_back({ a, 2 * d });
	}

	dijk_fox();
	dijk_wolf();

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int wolf_min = min(wolf_dist[i][0], wolf_dist[i][1]);
		if (wolf_min >= 1e9 || fox_dist[i] >= 1e9) continue;
		if (fox_dist[i] < wolf_min) ans++;
	}

	cout << ans << '\n';

	/*for (int i = 1; i <= n; i++) {
		if (fox_dist[i] >= 1e9)
			cout << "INF" << '\t';
		else
			cout << fox_dist[i] << '\t';
	}
	cout << '\n';

	for (int i = 1; i <= n; i++) {
		cout << i << ": ";
		for (int j = 0; j < 2; j++) {
			if (wolf_dist[i][j] >= 1e9)
				cout << "INF" << '\t';
			else
				cout << wolf_dist[i][j] << '\t';
		}
		cout << '\n';
	}*/

	return 0;
}