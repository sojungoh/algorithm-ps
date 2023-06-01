#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int *dist, **graph;

void dijkstra(int n, int c) {
	
	priority_queue<pair<int, int>> pq;
	
	dist[c] = 0;
	
	pq.push({0, c});
	
	while(!pq.empty()) {
		
		int d = -pq.top().first;
		int city = pq.top().second;
		pq.pop();
		
		if(dist[city] <= d)
			continue;
		
		for(int i = 1; i <= n; ++i) {
			if(i == c || graph[city][i] == 0)
				continue;
			
			if(dist[i] <= d + graph[city][i])
				continue;
				
			dist[i] = d + graph[city][i];
			pq.push({-dist[i], i});
		}
	}
	
	int city_count = 0, max_time = 0;
	for(int i = 1; i <= n; ++i) {
		if(i == c || dist[i] == int(1e9))
			continue;
			
		city_count++;
		max_time = max(max_time, dist[i]);
	}
	
	cout << city_count << ' ' << max_time << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, c;
	cin >> n >> m >> c;

	dist = new int[n + 1];
	fill(dist, dist + n + 1, int(1e9));
	 
	graph = new int*[n + 1];
	for(int i = 0; i <= n; ++i)
		graph[i] = new int[n + 1];
	fill(&graph[0][0], &graph[n][n + 1], 0);
		
	int x, y, z;
	for(int i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		graph[x][y] = z;
	}
	
	dijkstra(n, c);
	
	return 0;
}
