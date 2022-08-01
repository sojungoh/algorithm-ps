#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, d, dist[10001] = { 0, };
vector<vector<pair<int, int>>> road_info(10001);
priority_queue<pair<int, int>> min_heap;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		int s, a, r;
		cin >> s >> a >> r;
		road_info[s].push_back({ a, r });
	}

	for (int i = 0; i <= d; i++)
		dist[i] = i;

	min_heap.push({ 0, 0 });

	while (!min_heap.empty()) {
		int distance = -min_heap.top().first;
		int num = min_heap.top().second;
		min_heap.pop();

		if (dist[num] < distance) continue;

		for (int i = num; i <= d; i++) {
			if (dist[i] > distance + i - num) {
				dist[i] = distance + i - num;
			}

			if (!road_info.size()) continue;
			
			for (int j = 0; j < road_info[i].size(); j++) {
				int next = road_info[i][j].first;
				int next_d = road_info[i][j].second;

				if (dist[next] > dist[i] + next_d) {
					dist[next] = dist[i] + next_d;
					min_heap.push({ -dist[next], next });
				}
			}
		}
	}

	cout << dist[d] << '\n';

	return 0;
}