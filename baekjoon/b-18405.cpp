#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, s, x, y, map[201][201];
int v_time[201][201] = { 0, }, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
vector<pair<int, int>> vec;

void bfs() {
	queue<pair<int, int>> q;
	int ans = 0;

	for (int i = 0; i < vec.size(); i++)
		q.push(make_pair(vec[i].first, vec[i].second));

	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();
		int virus_num = map[curr_x][curr_y];

		if (v_time[curr_x][curr_y] > s) break;

		if (curr_x == x && curr_y == y) {
			ans = virus_num;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];

			if (next_x < 1 || next_y < 1 || next_x > n || next_y > n) continue;
			if (map[next_x][next_y] || v_time[next_x][next_y]) continue;

			v_time[next_x][next_y] = v_time[curr_x][curr_y] + 1;
			map[next_x][next_y] = virus_num;
			q.push(make_pair(next_x, next_y));
		}
	}
	cout << ans << '\n';
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return map[a.first][a.second] < map[b.first][b.second];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j]) vec.push_back(make_pair(i, j));
		}
	}

	cin >> s >> x >> y;

	sort(vec.begin(), vec.end(), cmp);
	bfs();

	return 0;
}