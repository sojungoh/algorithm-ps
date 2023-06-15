#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	
	int rank[n];
	int indegree[n + 1] = {0, };
	bool graph[n + 1][n + 1] = {0, };
    
	for(int i = 0; i < n; ++i)
		cin >> rank[i];
	
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			indegree[rank[j]] += 1;
			graph[rank[i]][rank[j]] = 1;
		}
	}
	
	int m, a, b;
	cin >> m;
	for(int i = 0; i < m; ++i) {
		cin >> a >> b;
		
		if(graph[a][b]) {	
			indegree[a] += 1;
			indegree[b] -= 1;
			graph[a][b] = 0;
			graph[b][a] = 1;
		}
		else if(graph[b][a]) {
			indegree[a] -= 1;
			indegree[b] += 1;
			graph[a][b] = 1;
			graph[b][a] = 0;
		}		
	}
	
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
	
	for(int out : ans)
		cout << out << ' ';
	cout << '\n';
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
