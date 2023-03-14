#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, ans = -1;
char map[10][10];
queue<pair<int, int>> q;

void solve() {
	bool goal_flag = false;
	int turn = 1, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };

	while (!q.empty()) {
		int q_sz = q.size();

		while (q_sz) {
			int direction = q.front().first;
			int curr_red[2] = { q.front().second / 1000, (q.front().second % 1000) / 100 };
			int curr_blue[2] = { (q.front().second % 100) / 10, q.front().second % 10 };
			q.pop();

			//cout << "red: " << curr_red[0] << ' ' << curr_red[1] << '\n';
			//cout << "blue: " << curr_blue[0] << ' ' << curr_blue[1] << '\n';

			if (turn > 10) break;

			for (int i = 0; i < 4; i++) {
				int red_x = curr_red[0], red_y = curr_red[1];
				int blue_x = curr_blue[0], blue_y = curr_blue[1];

				if (direction != -1 && (direction + i) % 2 == 0) continue;

				bool red_flag = true, blue_flag = true;

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

					if (map[blue_x + dx[i]][blue_y + dy[i]] == 'O') break;

					if (red_x == blue_x && red_y == blue_y) {
						if (red_flag) {
							red_x -= dx[i], red_y -= dy[i];
							red_flag = false;
						}
						else if (blue_flag) {
							blue_x -= dx[i], blue_y -= dy[i];
							blue_flag = false;
						}
					}
				}

				if (map[blue_x + dx[i]][blue_y + dy[i]] == 'O')
					continue;

				if (map[red_x + dx[i]][red_y + dy[i]] == 'O') {
					ans = turn;
					goal_flag = true;
					break;
				}

				q.push({ i, 1000 * red_x + 100 * red_y + 10 * blue_x + blue_y });
			}
			if (goal_flag) break;
			q_sz -= 1;
		}
		if (goal_flag) break;
		turn += 1;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int temp = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'R') {
				map[i][j] = '.';
				temp += 1000 * i + 100 * j;
			}
			else if (map[i][j] == 'B') {
				map[i][j] = '.';
				temp += 10 * i + j;
			}
		}
	}
	q.push({ -1, temp });

	solve();

	return 0;
}