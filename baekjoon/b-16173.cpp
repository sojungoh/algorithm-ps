#include <iostream>

using namespace std;

int n, map[3][3], visited[3][3] = { 0, }, dx[2] = { 1, 0 }, dy[2] = { 0, 1 };
bool ans_flag = false;

void dfs(int curr_x, int curr_y) {
	if (curr_x == n - 1 && curr_y == n - 1) {
		ans_flag = true;
		return;
	}

	visited[curr_x][curr_y] = 1;

	for (int i = 0; i < 2; i++) {
		int x = curr_x + dx[i] * map[curr_x][curr_y];
		int y = curr_y + dy[i] * map[curr_x][curr_y];

		if (x < 0 || y < 0 || x >= n || y >= n) continue;
		if (visited[x][y]) continue;
		dfs(x, y);

		if (ans_flag) break;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	dfs(0, 0);

	if (ans_flag)
		cout << "HaruHaru" << '\n';
	else
		cout << "Hing" << '\n';

	return 0;
}