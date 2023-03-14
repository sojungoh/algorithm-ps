#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m, map[101][101], dist[101][101] = { 0, };

void bfs() {
	int d[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	bool ans_flag = false;
	queue<pair<int, int>> q;
	
	dist[1][1] = 1;
 	q.push({ 1, 1 });

	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = curr_x + d[i][0];
			int y = curr_y + d[i][1];

			if (x < 1 || y < 1 || x > n || y > m) continue;
			if (dist[x][y] || !map[x][y]) continue;

			dist[x][y] = dist[curr_x][curr_y] + 1;

			if (x == n && y == m) {
				ans_flag = true;
				break;
			}

			q.push({ x, y });
		}
		if (ans_flag) break;
	}

	cout << dist[n][m] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
			map[i][j] = s[j - 1] - '0';
	}
		
	bfs();

	return 0;
}