#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int ** edges = new int*[n + 1];
	for(int i = 0; i <= n; ++i)
		edges[i] = new int[n + 1];
	fill(&edges[0][0], &edges[n][n + 1], int(1e9));
	
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			if(i == j) edges[i][j] = 0;
	
	int a, b;
	for(int i = 0; i < m; ++i) {
		cin >> a >> b;
		edges[a][b] = 1;
		edges[b][a] = 1;
	}
	
	int x, k;
	cin >> x >> k;
	
	// floyd warshall
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for(int d = 1; d <= n; ++d)
				edges[i][d] = min(edges[i][d], edges[i][j] + edges[j][d]);
	
	int ans;
	if(edges[1][k] == int(1e9) || edges[k][x] == int(1e9))
		ans = -1;
	else
		ans = edges[1][k] + edges[k][x];
	
	cout << ans << '\n';
	
	return 0;
}
