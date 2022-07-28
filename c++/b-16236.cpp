#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n, ans = 0, map[20][20], shark_sz = 2, shark[2] = { 0, }, fish_count = 0;

bool bfs() {
	bool flag = false;
	queue<pair<int, int>> q;
	
	int fish[2] = { 20, 20 }, min_dist = 1e9;
	int visited[20][20] = { 0, }, dist[20][20] = { 0, }, dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, -1, 1, 0 };
	
	visited[shark[0]][shark[1]] = 1;
	q.push({ shark[0], shark[1] });

	while (!q.empty()) {
		int curr_x = q.front().first, curr_y = q.front().second;
		q.pop();

		if (dist[curr_x][curr_y] > min_dist)
			break;

		for (int i = 0; i < 4; i++) {
			int x = curr_x + dx[i], y = curr_y + dy[i];

			if (x < 0 || y < 0 || x >= n || y >= n) continue;
			if (visited[x][y]) continue;
			if (shark_sz < map[x][y]) continue;

			dist[x][y] = dist[curr_x][curr_y] + 1;

			if (0 < map[x][y] && map[x][y] < shark_sz) {
				if (!flag) {
					min_dist = dist[x][y];
					flag = true;
				}

				if (min_dist == dist[x][y]) {
					if (fish[0] > x) {
						fish[0] = x;
						fish[1] = y;
					}
					else if (fish[0] == x)
						fish[1] = fish[1] > y ? y : fish[1];
				}
			}
			visited[x][y] = 1;
			q.push({ x, y });
		}
	}

	if (flag) {
		map[fish[0]][fish[1]] = 0;
		ans += min_dist;
		shark[0] = fish[0], shark[1] = fish[1];
	}

	return flag;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 9) {
				shark[0] = i, shark[1] = j;
				map[i][j] = 0;
			}
		}
	}

	while (bfs()) {
		fish_count++;

		if (shark_sz == fish_count) {
			shark_sz += 1;
			fish_count = 0;
		}
 	}

	cout << ans << '\n';

	return 0;
}