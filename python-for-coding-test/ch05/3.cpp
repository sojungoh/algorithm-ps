#include <iostream>
#include <queue>

using namespace std;

int n, m, map[1000][1000];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
bool visited[1000][1000] = {0, };

void solve(int i, int j) {
	
	queue<pair<int, int>> q;
	
	q.push({i, j});
	
	while(!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		visited[x][y] = 1;
		
		for(int d = 0; d < 4; ++d) {
			int next_x = x + dx[d];
			int next_y = y + dy[d];
			
			if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m)
				continue;
			
			if(map[next_x][next_y] || visited[next_x][next_y])
				continue;
			
			q.push({next_x, next_y});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int ans = 0;
	
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> map[i][j];
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(!map[i][j] && !visited[i][j]) {
				solve(i, j);
				ans += 1;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
