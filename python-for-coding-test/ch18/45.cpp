#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void topology_sort(int n, bool **graph, int *indegree) {
	
	queue<int> q;
	vector<int> ans;
	
	for(int i = 1; i <= n; ++i)
		if(indegree[i] == 0)
			q.push(i);
	
	while(!q.empty()) {
		if(q.size() != 1) {
			cout << "?" << '\n';
			return;
		}
		
		int curr = q.front();
		ans.push_back(curr);
		q.pop();
		
		for(int i = 1; i <= n; ++i) {
			if(graph[curr][i]) {
				indegree[i] -= 1;
				
				if(indegree[i] == 0)
					q.push(i);
			}
		}
	}
	
	if(ans.size() != n) {
		cout << "IMPOSSIBLE" << '\n';
		return;
	}
	
	for(int a : ans)
		cout << a << ' ';
	cout << '\n';
}

void solve() {
	int n;
	cin >> n;
	
	int rank[n];
	int indegree[n + 1] = {0, };
	bool **graph = new bool*[n + 1];
	for(int i = 0; i <= n; ++i)
		graph[i] = new bool[n + 1];
	fill(&graph[0][0], &graph[n][n + 1], false);
	
	for(int i = 0; i < n; ++i) {
		cin >> rank[i];
		
		for(int j = 0; j < i; ++j) {
			indegree[rank[j]] += 1;
			graph[rank[i]][rank[j]] = true;
		}
	}
	
	int m, a, b;
	cin >> m;
	for(int i = 0; i < m; ++i) {
		cin >> a >> b;
		
		if(graph[a][b]) {	
			indegree[a] += 1;
			indegree[b] -= 1;
			graph[a][b] = false;
			graph[b][a] = true;
		}
		if(graph[b][a]) {
			indegree[a] -= 1;
			indegree[b] += 1;
			graph[a][b] = true;
			graph[b][a] = false;
		}		
	}
	
	topology_sort(n, graph, indegree);
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
