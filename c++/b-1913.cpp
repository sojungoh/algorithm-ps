#include <iostream>
#include <cmath>

using namespace std;

int n, k, map[1000][1000], cord[3];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // ºÏ ¼­ ³² µ¿

void rotate_right() {
	if (cord[2] == 0)
		cord[2] = 3;
	else
		cord[2] -= 1;
}

void solve() {
	cord[0] = cord[1] = (n + 1) / 2;
	cord[2] = 0;

	int ans[2] = { 0, }, count = -1, idx = 1, check = 0;

	for (int num = 1; num <= pow(n, 2); num++) {
		map[cord[0]][cord[1]] = num;

		if (num == k) {
			ans[0] = cord[0];
			ans[1] = cord[1];
		}

		++count;
		if (count == idx) {
			count = 0;
			rotate_right();

			++check;
			if (check == 2) {
				check = 0;
				++idx;
			}
		}
		
		cord[0] += dx[cord[2]];
		cord[1] += dy[cord[2]];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << ans[0] << ' ' << ans[1] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	solve();

	return 0;
}