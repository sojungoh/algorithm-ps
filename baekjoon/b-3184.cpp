#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c, ans[2] = { 0, }, visited[250][250] = { 0, };
char map[250][250];
queue<pair<int, int>> q;

void bfs() {
	int o_count = 0, v_count = 0, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };

	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		if (map[curr_x][curr_y] == 'o') o_count += 1;
		else if (map[curr_x][curr_y] == 'v') v_count += 1;

		for (int i = 0; i < 4; i++) {
			int x = curr_x + dx[i];
			int y = curr_y + dy[i];

			if (x < 0 || y < 0 || x >= r || y >= c) continue;
			if (map[x][y] == '#' || visited[x][y]) continue;

			visited[x][y] = 1;
			q.push({ x, y });
		}
	}
	if (o_count > v_count) ans[0] += o_count;
	else ans[1] += v_count;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<pair<int, int>> coord;
	
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'o' || map[i][j] == 'v')
				coord.push_back({ i, j });
		}
	}

	for (int i = 0; i < coord.size(); i++) {
		int x = coord[i].first;
		int y = coord[i].second;

		if (visited[x][y]) continue;

		visited[x][y] = 1;
		q.push({ x, y });
		bfs();
	}

	cout << ans[0] << ' ' << ans[1] << '\n';

	return 0;
}