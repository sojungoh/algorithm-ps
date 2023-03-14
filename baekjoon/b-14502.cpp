#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, map[8][8] = { 0, }, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };

void bfs(queue<pair<int, int>>& q) {
	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		map[curr_x][curr_y] = 2;

		for (int i = 0; i < 4; i++) {
			int x = curr_x + dx[i];
			int y = curr_y + dy[i];

			if (x < 0 || y < 0 || x >= n || y >= m)
				continue;
			if (map[x][y]) continue;
			
			q.push(make_pair(x, y));
			map[x][y] = 2;
		}
	}
}


int virus() {
	int safe_zone = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}

	bfs(q);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!map[i][j]) safe_zone++;

	return safe_zone;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int original_map[8][8], ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			original_map[i][j] = map[i][j];
		}
	}

	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) {
			for (int x2 = 0; x2 < n; x2++) {
				for (int y2 = 0; y2 < m; y2++) {
					if (x1 == x2 && y1 == y2) continue;

					for (int x3 = 0; x3 < n; x3++) {
						for (int y3 = 0; y3 < m; y3++) {
							if (x1 == x3 && y1 == y3) continue;
							if (x2 == x3 && y2 == y3) continue;

							if (map[x1][y1] || map[x2][y2] || map[x3][y3]) continue;

							map[x1][y1] = map[x2][y2] = map[x3][y3] = 1;
							ans = max(ans, virus());

							copy(&original_map[0][0], &original_map[0][0] + 8 * 8, &map[0][0]);
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
	
	return 0;
}