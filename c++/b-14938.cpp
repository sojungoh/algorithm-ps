#include <iostream>
#include <algorithm>

using namespace std;

int n, m, r, ans = 0, map[101][101], item[101] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (i == j) map[i][j] = 0;
			else map[i][j] = int(1e9);
		}
	}

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
		cin >> item[i];

	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		map[a][b] = min(map[a][b], l);
		map[b][a] = min(map[b][a], l);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j || j == k || k == i) continue;
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (m < map[i][j]) continue;
			temp += item[j];
		}
		ans = max(ans, temp);
	}
	cout << ans << '\n';

	return 0;
}