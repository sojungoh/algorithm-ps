#include <iostream>
#include <cstring>

using namespace std;

int m, n;
int arr[501][501], route[501][501];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 }; // ºÏ ¼­ ³² µ¿

int solve(int x, int y) {

	if (route[x][y] != -1)
		return route[x][y];

	route[x][y] = 0;
	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > m || ny > n)
			continue;

		if (arr[nx][ny] >= arr[x][y])
			continue;

		route[x][y] += solve(nx, ny);
	}

	return route[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			route[i][j] = -1;
		}
	}

	route[m][n] = 1;

	cout << solve(1, 1) << '\n';

	return 0;
}