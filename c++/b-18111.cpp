#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, b, map[500][500];

void solve() {
	int ans[2] = { 2147483647, 0 };

	for (int height = 0; height < 257; height++) {
		int time = 0, block = b;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (height == map[i][j])
					continue;

				if (height < map[i][j]) {
					block += (map[i][j] - height);
					time += 2 * (map[i][j] - height);
				}
				else if (height > map[i][j]) {
					block -= (height - map[i][j]);
					time += height - map[i][j];
				}
			}
		}
		if (block < 0) continue;

		if (time == ans[0]) {
			if (height > ans[1]) ans[1] = height;
		}
		else {
			if (time < ans[0]) {
				ans[0] = time;
				ans[1] = height;
			}
		}
	}

	cout << ans[0] << ' ' << ans[1] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	solve();

	return 0;
}