#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, map[300][300], visited[300][300], dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int count = 0;
		int curr_x = q.front().first, curr_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = curr_x + dx[i];
			int y = curr_y + dy[i];

			if (x < 0 || y < 0 || x >= n || y >= m) continue;
			if (visited[x][y]) continue;

			if (!map[x][y]) {
				if (count < map[curr_x][curr_y])
					count++;
				continue;
			}
			visited[x][y] = 1;
			q.push({ x, y });
		}
		map[curr_x][curr_y] -= count;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans = 0;
	vector<pair<int, int>> coord;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	while (1) {
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j]) coord.push_back({ i, j });

		if (!coord.size()) {
			ans = 0;
			break;
		}

		visited[coord[0].first][coord[0].second] = 1;
		q.push({ coord[0].first, coord[0].second });

		bfs();
		
		bool flag = false;
		for (int i = 0; i < coord.size(); i++) {
			if (!visited[coord[i].first][coord[i].second]) {
				flag = true;
				break;
			}
		}
		if (flag) break;
		
		ans += 1;
		coord.clear();
	}

	cout << ans << '\n';

	return 0;
}