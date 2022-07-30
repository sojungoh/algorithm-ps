#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, ans = -1;
char map[10][10];
queue<pair<int, int>> q_red;
queue<pair<int, int>> q_blue;

void solve() {
	int visited[10][10] = { 0, }, dist[10][10] = { 0, }, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };

	//visited[q_red.front().first][q_red.front().second] = 1;
	//visited[q_blue.front().first][q_blue.front().second] = 1;

	while (!q_red.empty() && !q_blue.empty()) {
		int curr_red[2] = { q_red.front().first, q_red.front().second };
		q_red.pop();
		int curr_blue[2] = { q_blue.front().first, q_blue.front().second };
		q_blue.pop();

		if (dist[curr_red[0]][curr_red[1]] > 10) break;

		cout << '\n';

		for (int i = 0; i < 4; i++) {
			int red_x = curr_red[0], red_y = curr_red[1];
			int blue_x = curr_blue[0], blue_y = curr_blue[1];

			if (map[red_x + dx[i]][red_y + dy[i]] == '#') continue;
			if (visited[red_x + dx[i]][red_y + dy[i]]) continue;

			bool red_flag = true, blue_flag = true, goal_flag = true;

			while (red_flag || blue_flag) {
				red_flag = false, blue_flag = false;

				if (map[red_x + dx[i]][red_y + dy[i]] == '.') {
					red_x += dx[i], red_y += dy[i];
					red_flag = true;
				}
				if (map[blue_x + dx[i]][blue_y + dy[i]] == '.') {
					blue_x += dx[i], blue_y += dy[i];
					blue_flag = true;
				}

				if (map[blue_x + dx[i]][blue_y + dy[i]] == 'O') {
					goal_flag = false;
					break;
				}
				if (map[red_x + dx[i]][red_y + dy[i]] == 'O')
					goal_flag = true;

				if (red_x == blue_x && red_y == blue_y) {
					if (red_flag) {
						visited[red_x][red_y] = 0;
						red_x -= dx[i], red_y -= dy[i];
						red_flag = false;
					}
					else if (blue_flag) {
						blue_x -= dx[i], blue_y -= dy[i];
						blue_flag = false;
					}
				}
			}
			dist[red_x][red_y] = dist[curr_red[0]][curr_red[1]] + 1;

			if (!goal_flag) continue;
			if (map[red_x + dx[i]][red_y + dy[i]] == 'O') {
				ans = dist[red_x][red_y];
				break;
			}

			if (red_x == curr_red[0] && red_y == curr_red[1]) continue;
			
			visited[red_x - dx[i]][red_y - dy[i]] = 1;
			q_red.push({ red_x, red_y });
			q_blue.push({ blue_x, blue_y });
			cout << "red: " << red_x << ' ' << red_y << '\n';
			cout << "blue: " << blue_x << ' ' << blue_y << '\n';
		}
		if (ans != -1) break;
	}

	cout << ans << '\n';

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'R') {
				map[i][j] = '.';
				q_red.push({ i, j });
			}
			else if (map[i][j] == 'B') {
				map[i][j] = '.';
				q_blue.push({ i, j });
			}
		}
	}

	solve();

	return 0;
}