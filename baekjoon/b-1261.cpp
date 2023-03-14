#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m, map[101][101], wall[101][101], dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1, 1 });

	while (!q.empty()) {
		int curr_x = q.front().first, curr_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = curr_x + dx[i], y = curr_y + dy[i];

			if (x < 1 || y < 1 || x > n || y > m) continue;

			int check = (map[x][y] == 0) ? wall[curr_x][curr_y] : wall[curr_x][curr_y] + 1;
			if (wall[x][y] <= check) continue;
			wall[x][y] = check;

			if (x == n && y == m)
				continue;

			q.push({ x, y });
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (wall[i][j] >= 1e9) cout << "INF" << '\t';
			else cout << wall[i][j] << '\t';
		}
		cout << '\n';
	}*/

	cout << wall[n][m] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			map[i][j] = s[j - 1] - '0';
			wall[i][j] = int(1e9);
		}
	}
	wall[1][1] = 0;
	
	bfs();

	return 0;
}