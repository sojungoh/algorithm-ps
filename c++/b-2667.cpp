#include <iostream>
#include <queue>
#include <functional>
#include <string>

using namespace std;

int n, map[25][25], visited[25][25] = { 0, };
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
priority_queue<int, vector<int>, greater<int>> min_heap;
queue<pair<int, int>> q;

void bfs() {
	int num = 0;
	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();
		++num;

		for (int i = 0; i < 4; i++) {
			int x = curr_x + dx[i];
			int y = curr_y + dy[i];

			if (x < 0 || y < 0 || x >= n || y >= n) continue;
			if (!map[x][y] || visited[x][y]) continue;
			
			visited[x][y] = 1;
			q.push({ x, y });
		}
	}
	min_heap.push(num);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++)
			map[i][j] = s[j] - '0';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j] || visited[i][j]) continue;
			
			visited[i][j] = 1;
			q.push({ i, j });

			bfs();
		}
	}

	cout << min_heap.size() << '\n';

	while (!min_heap.empty()) {
		cout << min_heap.top() << '\n';
		min_heap.pop();
	}

	return 0;
}