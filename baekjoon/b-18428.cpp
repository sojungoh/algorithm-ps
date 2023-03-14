#include <iostream>
#include <vector>
using namespace std;

int n, visited[7][7] = { 0, };
char map[7][7];
bool s_flag = false;
vector<pair<int, int>> ob_idx;
vector<pair<int, int>> t_idx;

bool check() {
	char new_map[7][7];
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			new_map[i][j] = map[i][j];

	for (int i = 0; i < 3; i++)
		new_map[ob_idx[i].first][ob_idx[i].second] = 'O';

	for (int i = 0; i < t_idx.size(); i++) {
		int curr_x = t_idx[i].first;
		int curr_y = t_idx[i].second;

		for (int j = 0; j < 4; j++) {
			int x = curr_x + dx[j];
			int y = curr_y + dy[j];

			while ((0 < x && x <= n) && (0 < y && y <= n)) {
				if (new_map[x][y] == 'O') break;

				if (new_map[x][y] == 'S')
					return false;

				x += dx[j];
				y += dy[j];
			}
		}
	}
	return true;
}

void combination(int x, int y) {
	if (ob_idx.size() == 3) {
		s_flag = check();
		return;
	}

	for (int i = x; i <= n; i++) {
		for (int j = y; j <= n; j++) {
			if (map[i][j] != 'X' || visited[i][j]) continue;
			
			visited[i][j] = 1;
			ob_idx.push_back(make_pair(i, j));
			combination(i, j);

			if (s_flag)
				return;

			ob_idx.pop_back();
			visited[i][j] = 0;
		}
		y = 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'T')
				t_idx.push_back(make_pair(i, j));
		}
	}
		
	combination(1, 1);

	if (s_flag)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}