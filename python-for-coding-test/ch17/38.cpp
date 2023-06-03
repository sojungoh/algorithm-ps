#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int graph[501][501];

void solve() {
	
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			if(i == k) continue;
			for(int j = 1; j <= n; ++j) {
				if(j == k || j == i) continue;
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int count = 0;
		
		for(int j = 1; j <= n; ++j) {
			if(graph[i][j] < int(1e9) || graph[j][i] < int(1e9))
				count += 1;
		}
		
		if(count == n)
			ans += 1;
	}
	
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = int(1e9);
		}
	}
	
	int a, b;
	for(int i = 0; i < m; ++i) {
		cin >> a >> b;
		graph[a][b] = 1;
	}
	
	solve();
	
	return 0;
}
