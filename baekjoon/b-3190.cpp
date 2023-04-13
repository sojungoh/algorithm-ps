#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, map[102][102] = { 0, };
int dx[4] = { -1, 0, 1, 0 }, dy[4] = {0, -1, 0, 1};
vector<pair<int, char>> info;

void rotate_snake(int* arr, char c) {
	if (c == 'L') {
		if (arr[2] == 3)
			arr[2] = 0;
		else
			arr[2] += 1;
	}
	else if (c == 'D') {
		if (arr[2] == 0)
			arr[2] = 3;
		else
			arr[2] -= 1;
	}
}

void solve() {
	int time[2] = { 1, 1 }, head[3] = { 1, 1, 3 }, tail[3] = { 1, 1, 3 }, h = 0, t = 0;

	map[1][1] = 3;

	while (1) {
		int x = head[0] + dx[head[2]];
		int y = head[1] + dy[head[2]];
		int next = map[x][y];

		if (!next || next == 3) break;

		if (next == 1) {
			map[tail[0]][tail[1]] = 1;
			map[x][y] = 3;
			head[0] = x;
			head[1] = y;
			tail[0] += dx[tail[2]];
			tail[1] += dy[tail[2]];

			if (t != info.size() && info[t].first == time[1]) {
				rotate_snake(tail, info[t].second);
				++t;
			}

			time[1] += 1;
		}
		else if (next == 2) {
			map[x][y] = 3;
			head[0] = x;
			head[1] = y;
		}

		if (h != info.size() && info[h].first == time[0]) {
			rotate_snake(head, info[h].second);
			++h;
		}
		time[0] += 1;
	}
	cout << time[0] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int x, y, d, t;
	char c;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 1;
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		map[x][y] = 2;
	}

	cin >> d;

	for (int i = 0; i < d; i++) {
		cin >> t >> c;
		info.push_back(make_pair(t, c));
	}

	solve();

	return 0;
}
