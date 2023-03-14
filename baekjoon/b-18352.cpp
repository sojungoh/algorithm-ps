#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int n, m, k, x, visited[300001] = { 0, }, dist[300001] = { 0, };
queue<int> q;
priority_queue<int, vector<int>, greater<int>> min_heap;
vector<pair<int, int>> map;

void bfs() {
	q.push(x);

	while (!q.empty()) {
		int curr_city = q.front();
		q.pop();
		visited[curr_city] = 1;

		if (dist[curr_city] >= k) break;

		int idx = 0;
		for (; idx < map.size(); idx++)
			if (map[idx].first == curr_city) break;

		for (int i = idx; i < map.size(); i++) {
			if (curr_city != map[i].first) break;
			if (visited[map[i].second]) continue;

			int next_city = map[i].second;
			q.push(next_city);
			visited[next_city] = 1;
			dist[next_city] = dist[curr_city] + 1;

			if (dist[next_city] == k) min_heap.push(next_city);
		}
	}

	if (min_heap.empty())
		cout << -1 << '\n';
	else {
		while (!min_heap.empty()) {
			cout << min_heap.top() << '\n';
			min_heap.pop();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k >> x;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map.push_back(make_pair(a, b));
	}

	sort(map.begin(), map.end());

	bfs();

	return 0;
}