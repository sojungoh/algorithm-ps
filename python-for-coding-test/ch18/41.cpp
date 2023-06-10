#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int **graph = new int*[n + 1];
	for(int i = 0; i <= n; ++i)
		graph[i] = new int[n + 1];
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> graph[i][j];
			
			if(graph[i][j] == 0)
				graph[i][j] = int(1e9);
		}
	}
			
	int *plan = new int[m];
	for(int i = 0; i < m; ++i)
		cin >> plan[i];
	
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			if(i == k) continue;
			for(int j = 1; j <= n; ++j) {
				if(i == j || j == k) continue;
				
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	int s, e;
	bool flag = true;
	for(int i = 0; i < m - 1; ++i) {
		s = plan[i];
		e = plan[i + 1];
		
		if(graph[s][e] >= int(1e9)) {
			flag = false;
			break;
		}
	}
	
	if(flag)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	
	return 0;
}
