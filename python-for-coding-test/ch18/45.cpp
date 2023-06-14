#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	
	int rank[n];
	vector<vector<int>> graph(n + 1);
	
	for(int i = 0; i < n; ++i) {
		cin >> rank[i];
		
		for(int j = 0; j < i; ++j)
			graph[rank[j]].push_back(rank[i]);
	}
	
	int m, a, b;
	cin >> m;
	for(int i = 0; i < m; ++i) {
		cin >> a >> b;
		
		 
	}
		
	
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}
