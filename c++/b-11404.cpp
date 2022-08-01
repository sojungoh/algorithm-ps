#include <iostream>
#include <cmath>

using namespace std;

int n, m, bus[101][101] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			bus[i][j] = int(1e9);

	for (int i = 0; i < m; i++) {
		int s, a, c;
		cin >> s >> a >> c;
		bus[s][a] = (bus[s][a] == int(1e9)) ? c : min(bus[s][a], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j || j == k || k == i) continue;
				bus[i][j] = min(bus[i][j], bus[i][k] + bus[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (bus[i][j] >= int(1e9))
				cout << 0 << ' ';
			else cout << bus[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}