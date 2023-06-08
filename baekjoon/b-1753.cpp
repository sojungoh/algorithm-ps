#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int *dist, **graph;

void solve(int v, int k) {
	
	priority_queue<pair<int, int>> pq;
	
	pq.push({0, k});
	
	while(!pq.empty()) {
		
		int curr = pq.top().second;
		pq.pop();
		
		for(int i = 1; i <= v; ++i) {
			if(graph[curr][i] == int(1e9))
				continue;
			
			if(dist[i] <= dist[curr] + graph[curr][i])
				continue;
			
			dist[i] = dist[curr] + graph[curr][i];
			pq.push({-dist[i], i});
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
	
	dist = new int[v + 1];
	fill(dist, dist + v + 1, int(1e9));
	dist[k] = 0;
	
	graph = new int*[v + 1];
	for(int i = 0; i <= v; ++i)
		graph[i] = new int[v + 1];
	fill(&graph[0][0], &graph[v][v + 1], int(1e9));

	for(int i = 0; i < e; ++i) {
		cin >> u >> x >> w;
		graph[u][x] = min(graph[u][x], w);
	}
	
	solve(v, k);
	
	return 0;
}
