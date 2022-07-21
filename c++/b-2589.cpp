#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

char map[50][50];
int n, m, visit[50][50], dist[50][50];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;

int bfs(int max_dist) {
	if (q.empty())
		return max_dist;
	
	int curr_x = q.front().first;
	int curr_y = q.front().second;
	q.pop();
	
	visit[curr_x][curr_y] = 1;
	max_dist = max(max_dist, dist[curr_x][curr_y]);

	for (int k = 0; k < 4; k++) {
		int x = curr_x + dx[k];
		int y = curr_y + dy[k];

		if (x < 0 || y < 0 || x >= n || y >= m)
			continue;

		if (map[x][y] == 'W' || visit[x][y])
			continue;

		visit[x][y] = 1;
		dist[x][y] = dist[curr_x][curr_y] + 1;
		q.push(make_pair(x, y));
	}

	return bfs(max_dist);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'W')
				continue;

			memset(visit, 0, sizeof(visit));
			memset(dist, 0, sizeof(dist));
			
			q.push(make_pair(i, j));
			ans = max(ans, bfs(0));
		}
	}
	cout << ans << '\n';

	return 0;
}