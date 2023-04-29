#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, map[1000][1000];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
vector<pair<int, int>> tomato_coord;

int bfs() {
	
	int day = -1;
	
	queue<pair<int, int>> q;
	
	for(pair<int, int> p : tomato_coord)
		q.push({p.first, p.second});
	
	while(!q.empty()) {
		
		size_t sz = q.size();
		
		for(int i = 0; i < sz; ++i) {
		
			int x = q.front().first;
			int y = q.front().second;
		
			q.pop();
		
			for(int d = 0; d < 4; ++d) {
				int nx = x + dx[d];
				int ny = y + dy[d];
			
				if(nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;
			
				if(map[nx][ny] != 0)
					continue;
			
				map[nx][ny] = 1;
			
				q.push({nx, ny});
			}
		}
		
		day += 1;
	}
	
	return day;
}

void solve() {
	
	int ans = bfs();
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(map[i][j] == 0) {
				ans = -1;
				break;
			}
		}
	}
	
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> m >> n;
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> map[i][j];;
			
			if(map[i][j] == 1)
				tomato_coord.push_back({i, j});
		}
	}
	
	solve();
	
	return 0;
}
