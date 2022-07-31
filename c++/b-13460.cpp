#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, ans = -1;
char map[10][10];
queue<pair<int, int>> q_red;
queue<pair<int, int>> q_blue;

void solve() {
	bool goal_flag = false;
	int red_visit[10][10] = { 0, }, blue_visit[10][10] = { 0, };
	int dist[10][10] = { 0, }, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };

	int turn = 0;

	red_visit[q_red.front().first][q_red.front().second] = 1;
	blue_visit[q_blue.front().first][q_blue.front().second] = 1;

	while (!q_red.empty() && !q_blue.empty()) {
		int curr_red[2] = { q_red.front().first, q_red.front().second };
		q_red.pop();
		int curr_blue[2] = { q_blue.front().first, q_blue.front().second };
		q_blue.pop();

		//if (dist[curr_red[0]][curr_red[1]] > 20) break;
		//if (turn > 10) break;

		cout << "red: " << curr_red[0] << ' ' << curr_red[1] << '\n';
		cout << "blue: " << curr_blue[0] << ' ' << curr_blue[1] << '\n';

		for (int i = 0; i < 4; i++) {
			int red_x = curr_red[0], red_y = curr_red[1];
			int blue_x = curr_blue[0], blue_y = curr_blue[1];

			if (map[red_x + dx[i]][red_y + dy[i]] == '#') continue;

			bool red_flag = true, blue_flag = true;

			while (red_flag || blue_flag) {
				red_flag = false, blue_flag = false;

				if (map[red_x + dx[i]][red_y + dy[i]] == '.') {
					red_x += dx[i], red_y += dy[i];
					//visited[red_x][red_y] = 1;
					red_flag = true;
				}
				if (map[blue_x + dx[i]][blue_y + dy[i]] == '.') {
					blue_x += dx[i], blue_y += dy[i];
					blue_flag = true;
				}

				if (map[blue_x + dx[i]][blue_y + dy[i]] == 'O') break;

				//if (map[red_x + dx[i]][red_y + dy[i]] == 'O')
				//	goal_flag = true;

				if (red_x == blue_x && red_y == blue_y) {
					if (red_flag) {
						//visited[red_x][red_y] = 0;
						red_x -= dx[i], red_y -= dy[i];
						red_flag = false;
					}
					else if (blue_flag) {
						blue_x -= dx[i], blue_y -= dy[i];
						blue_flag = false;
					}
				}
			}

			//if (red_visit[red_x][red_y] && blue_visit[blue_x][blue_y]) continue;

			//if (0 < dist[red_x][red_y] && dist[red_x][red_y] <= dist[curr_red[0]][curr_red[1]] + 1) continue;

			//red_visit[red_x][red_y] = 1;
			//blue_visit[blue_x][blue_y] = 1;
			dist[red_x][red_y] = dist[curr_red[0]][curr_red[1]] + 1;

			if (map[blue_x + dx[i]][blue_y + dy[i]] == 'O')
				continue;

			if (map[red_x + dx[i]][red_y + dy[i]] == 'O') {
				ans = dist[red_x][red_y];
				goal_flag = true;
				break;
			}

			q_red.push({ red_x, red_y });
			q_blue.push({ blue_x, blue_y });
		}
		if (goal_flag) break;

		//turn += 1;
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