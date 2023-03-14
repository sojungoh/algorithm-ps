#include <iostream>
#include <queue>

using namespace std;

int n, m, ans = 0;
int visited[50][50] = { 0, }, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
char map[50][50];
queue<pair<int, int>> q;

void bfs(int num) {
	char c = (num == 0) ? '-' : '|';

	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		for (int i = num; i < 4; i += 2) {
			int x = curr_x + dx[i];
			int y = curr_y + dy[i];
			
			if (x < 0 || y < 0 || x >= n || y >= m) continue;
			if (visited[x][y] || map[x][y] == c) continue;

			visited[x][y] = 1;
			q.push({ x, y });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) continue;
			
			visited[i][j] = 1;
			q.push({ i, j });

			if (map[i][j] == '|')
				bfs(0);
			else if (map[i][j] == '-')
				bfs(1);

			ans += 1;
		}
	}
	cout << ans << '\n';

	return 0;
}