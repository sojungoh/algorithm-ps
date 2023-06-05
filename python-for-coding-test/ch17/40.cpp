#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> edges(20001);

void solve() {
	priority_queue<pair<long long, int>> pq; 
	long long *dist = new long long[n + 1];
	fill(dist, dist + n + 1, int(1e11));
	
	dist[1] = 0;
	pq.push({0, 1});
	
	long long max_dist = 0;
	while(!pq.empty()) {
		
		int curr = pq.top().second;
		max_dist = max(max_dist, -pq.top().first);
		pq.pop();
		
		for(int next : edges[curr]) {
			
			if(dist[next] <= dist[curr] + 1)
				continue;
			
			dist[next] = dist[curr] + 1;
			pq.push({-dist[next], next});
		}
	}
	
	int num = 0, count = 0;
	for(int i = 2; i <= n; ++i) {	
		if(max_dist == dist[i]) {
			if(num == 0)
				num = i;
			count++;
		}
	}
	
	cout << num << ' ' << max_dist << ' ' << count << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	int a, b;
	for(int i = 0; i < m; ++i) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	solve();
	
	return 0;
}
