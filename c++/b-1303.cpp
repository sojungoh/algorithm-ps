#include <iostream>
#include <queue>

using namespace std;

int n, m, ans[2] = { 0, }, visited[100][100] = { 0, };
char map[100][100];
queue<pair<int, int>> q;

void bfs(char c) {
	int soldier = 0, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };

	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();
		soldier++;

		for (int i = 0; i < 4; i++) {
			int x = curr_x + dx[i];
			int y = curr_y + dy[i];

			if (x < 0 || y < 0 || x >= m || y >= n) continue;
			if (visited[x][y] || map[x][y] != c) continue;

			visited[x][y] = 1;
			q.push({ x, y });
		}
	}
	if (c == 'W') ans[0] += soldier * soldier;
	else if (c == 'B') ans[1] += soldier * soldier;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			q.push({ i, j });
			bfs(map[i][j]);
		}
	}

	cout << ans[0] << ' ' << ans[1] << '\n';

	return 0;
}