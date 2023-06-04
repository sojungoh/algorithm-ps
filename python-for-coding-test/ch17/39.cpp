#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

struct Space_info {
	int dist;
	int x;
	int y;
	
	Space_info(int _dist, int _x, int _y) 
		: dist(_dist), x(_x), y(_y)
	{}
};

struct compare_dist {
	bool operator()(Space_info const& s1, Space_info const& s2) {
		return s1.dist > s2.dist;	
	}
};

void solve() {
	
	int n;
	cin >> n;
	
	int cost[125][125], dist[125][125];
	priority_queue<Space_info, vector<Space_info>, compare_dist> pq;
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> cost[i][j];
	
	fill(&dist[0][0], &dist[n][n + 1], int(1e9));
	dist[0][0] = cost[0][0];
	pq.push(Space_info(dist[0][0], 0, 0));
	
	while(!pq.empty()) {
		int curr_x = pq.top().x;
		int curr_y = pq.top().y;
		
		pq.pop();
		
		if(curr_x == n - 1 && curr_y == n - 1)
			break;
		
		for(int i = 0; i < 4; ++i) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			
			if(dist[nx][ny] <= dist[curr_x][curr_y] + cost[nx][ny])
				continue;
			
			dist[nx][ny] = dist[curr_x][curr_y] + cost[nx][ny];
			
			pq.push(Space_info(dist[nx][ny], nx, ny));
		}
	}
	
	cout << dist[n - 1][n - 1] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		solve();
	}
	
	return 0;
}
