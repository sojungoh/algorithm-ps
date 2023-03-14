#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n, map[200][200], chess[2][2], visited[200][200] = { 0, }, dist[200][200] = {0, };
int dx[6] = { -2, -2, 0, 2, 2, 0 }, dy[6] = { -1, 1, -2, -1, 1, 2 };

void bfs() {
	queue<pair<int, int>> q;
	int ans = -1;

	visited[chess[0][0]][chess[0][1]] = 1;
	q.push({ chess[0][0], chess[0][1] });

	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int x = curr_x + dx[i];
			int y = curr_y + dy[i];

			if (x < 0 || y < 0 || x >= n || y >= n) continue;
			if (visited[x][y] && dist[curr_x][curr_y] + 1 >= dist[x][y]) continue;
			
			dist[x][y] = dist[curr_x][curr_y] + 1;
			visited[x][y] = 1;

			if (x == chess[1][0] && y == chess[1][1])
				ans = (ans == -1) ? dist[x][y] : min(ans, dist[x][y]);

			q.push({ x, y });
		}
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			cin >> chess[i][j];

	bfs();

	return 0;
}