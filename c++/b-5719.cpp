#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> route(500);
vector<vector<pair<int, int>>> map(500);
int s, d, ans = -1, visited[500], dist[500], min_edge[500][500] = { 0, };
bool min_flag = false;

int branch = -1;

void dfs(int curr, int sum) {
	if (curr == s) {
		if (sum == dist[d])
			min_flag = true;
		else {
			if (branch == d)
				ans = (ans == -1) ? sum : min(ans, sum);
		}

		return;
	}

	for (int i = 0; i < route[curr].size(); i++) {
		min_flag = false;
		int next = route[curr][i].second;

		if (min_edge[next][curr]) {
			continue;
		}

		if (visited[next]) continue;
		visited[next] = 1;
		dfs(next, sum + route[curr][i].first);
		visited[next] = 0;

		if (branch == curr) {
			min_flag = true;
		}

		if (min_flag) {
			branch = curr;
			min_edge[next][curr] = 1;
		}

		if (ans != -1) break;
	}
}

void solve(int n, int m) {
	cin >> s >> d;

	priority_queue<pair<int, int>> min_heap;

	for (int i = 0; i < m; i++) {
		int u, v, p;
		cin >> u >> v >> p;
		map[u].push_back({ v, p });
	}

	for (int i = 0; i < n; i++)
		dist[i] = int(1e9);
	dist[s] = 0;
	min_heap.push({ 0, s });

	while (!min_heap.empty()) {
		int heap_d = -min_heap.top().first;
		int curr = min_heap.top().second;
		min_heap.pop();

		if (dist[curr] < heap_d) continue;

		for (int i = 0; i < map[curr].size(); i++) {
			int next = map[curr][i].first;
			int cost = map[curr][i].second;

			if (next != s)
				route[next].push_back({ cost, curr });

			if (dist[next] <= dist[curr] + cost)
				continue;

			dist[next] = dist[curr] + cost;
			min_heap.push({ -dist[next], next });
		}
	}

	for (int i = 0; i < n; i++) {
		if (!route[i].size()) continue;
		sort(route[i].begin(), route[i].end());
	}

	visited[d] = 1;
	dfs(d, 0);

	cout << ans << '\n';

	/*for (int i = 0; i < n; i++)
		cout << visited[i] << '\t';
	cout << '\n';*/

	/*for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j = 0; j < route[i].size(); j++) {
			cout << route[i][j].first << ' ' << route[i][j].second << '\t';
		}
		cout << '\n';
	}*/
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;

	while (1) {
		cin >> n >> m;
		if (!n && !m) break;

		solve(n, m);

		for (int i = 0; i < n; i++) {
			route[i].clear();
			map[i].clear();
		}

		ans = -1;
		min_flag = false;
		memset(dist, 0, sizeof(dist));
		memset(visited, 0, sizeof(visited));
		memset(min_edge, 0, sizeof(min_edge));
	}	

	return 0;
}