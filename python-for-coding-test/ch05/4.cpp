#include <iostream>
#include <queue>

using namespace std;

int n, m, map[201][201];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

void solve() {
	
	queue<pair<int, int>> q;
	
	q.push({1, 1});
	
	map[1][1] = 2;
	
	while(!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		
		if(x == n && y == m)
			break;
		
		q.pop();
		
		for(int i = 0; i < 4; ++i) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			
			if(next_x < 1 || next_y < 1 || next_x > n || next_y > m)
				continue;
			
			// monster placed
			if(map[next_x][next_y] == 0)
				continue;
			
			// already visited
			if(1 < map[next_x][next_y] && map[next_x][next_y] <= map[x][y])
				continue;
			
			map[next_x][next_y] = map[x][y] + 1;
			
			q.push({next_x, next_y});
		}
	}
	
	cout << map[n][m] - 1 << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> map[i][j];
	
	solve();
	
	return 0;
}
