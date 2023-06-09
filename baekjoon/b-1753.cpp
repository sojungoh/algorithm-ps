#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int *dist;
vector<vector<pair<int, int>>> graph(20001);

void solve(int v, int k) {
	
	priority_queue<pair<int, int>> pq;
	
	pq.push({0, k});
	
	while(!pq.empty()) {
		
		int curr = pq.top().second;
		pq.pop();
		
		for(pair<int, int> p : graph[curr]) {
			if(dist[p.first] <= dist[curr] + p.second)
				continue;
			
			dist[p.first] = dist[curr] + p.second;
			pq.push({-dist[p.first], p.first});
		}
	}
	
	for(int i = 1; i <= v; ++i) {
		if(dist[i] >= int(1e9))
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int v, e, k, u, x, w;
	cin >> v >> e >> k;
	
	graph.resize(v + 1);
	
	dist = new int[v + 1];
	fill(dist, dist + v + 1, int(1e9));
	dist[k] = 0;
	
	for(int i = 0; i < e; ++i) {
		cin >> u >> x >> w;
		graph[u].push_back({x, w});
	}
	
	solve(v, k);
	
	return 0;
}
