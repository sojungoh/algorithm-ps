#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int n, l, r, map[50][50], visited[50][50] = { 0, };
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
bool union_flag = false;

void bfs(queue<pair<int, int>>& q) {
	int union_sum = 0, union_size = 0;
	vector<pair<int, int>> union_idx;
	union_idx.push_back({ q.front().first, q.front().second });

	while (!q.empty()) {
		int curr_x = q.front().first, curr_y = q.front().second;
		q.pop();
		visited[curr_x][curr_y] = 1;
		union_sum += map[curr_x][curr_y];
		union_size++;

		for (int i = 0; i < 4; i++) {
			int x = curr_x + dx[i], y = curr_y + dy[i];

			if (x < 0 || y < 0 || x >= n || y >= n) continue;
			if (visited[x][y]) continue;

			int gap = abs(map[curr_x][curr_y] - map[x][y]);
			if (gap < l || gap > r) continue;

			union_flag = true;
			visited[x][y] = 1;
			union_idx.push_back({ x, y });
			q.push({ x, y });
		}
	}

	for (int i = 0; i < union_idx.size(); i++)
		map[union_idx[i].first][union_idx[i].second] = union_sum / union_size;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans = 0;
	queue<pair<int, int>> q;

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) continue;
				q.push({ i, j });
				bfs(q);
			}
		}

		if (union_flag) {
			ans += 1;
			union_flag = false;

			memset(visited, 0, sizeof(visited));
		}
		else
			break;
	}

	cout << ans << '\n';

	return 0;
}