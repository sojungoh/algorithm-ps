#include <iostream>
#include <algorithm>

using namespace std;

int v, e, dist[401][401];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;

	fill(&dist[1][1], &dist[400][401], int(1e9));

	for (int i = 1; i <= e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}

	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = -1;
	for (int i = 1; i <= v; i++) {
		if (dist[i][i] >= 1e9) continue;
		ans = (ans == -1) ? dist[i][i] : min(ans, dist[i][i]);
	}

	cout << ans << '\n';
	
	return 0;
}