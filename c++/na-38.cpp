#include <iostream>
#include <cmath>

using namespace std;

int n, m, student[501][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) student[i][j] = 0;
			else student[i][j] = int(1e9);
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		student[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j || j == k || k == i) continue;
				student[i][j] = min(student[i][j], student[i][k] + student[k][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int in = 0, out = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (student[i][j] < 1e9) {
				++in;
			}
			if (student[j][i] < 1e9) {
				++out;
			}
		}

		if (in + out == n - 1)
			++ans;
	}

	cout << ans << '\n';

	return 0;
}