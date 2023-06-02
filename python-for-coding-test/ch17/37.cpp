#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int graph[101][101];

void solve() {
	// floyd-warshall
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {			
			for(int j = 1; j <= n; ++j) {
				if(i == j || j == k || k == i) continue;
				
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	int out;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(graph[i][j] < int(1e7))
				out = graph[i][j];
			else
				out = 0;
			
			cout << out << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	fill(&graph[0][0], &graph[100][101], int(1e7));
	
	for(int i = 1; i <= n; ++i)
		graph[i][i] = 0;
	
	int a, b, c;
	for(int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}
	
	solve();
	
	return 0;
}
