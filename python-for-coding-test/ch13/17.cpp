#include <iostream>
#include <queue>

using namespace std;

int n, k, s, x, y, map[201][201];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;

void solve() {
	
	int time = 0;
	
	while(!q.empty()) {
		
		bool flag = false;
		size_t sz = q.size();
		
		if(time == s)
			break;
			
		// must be sorted
		
		for(int t = 0; t < sz; ++t) {
		
			int a = q.front().first;
			int b = q.front().second;
		
			q.pop();
			
			if(a == x && b == y) {
				flag = true;
				break;
			}
			
			for(int i = 0; i < 4; ++i) {
				int nx = a + dx[i];
				int ny = b + dy[i];
				
				if(nx < 1 || ny < 1 || nx > n || ny > n)
					continue;
				
				if(map[nx][ny] != 0)
					continue;
				
				map[nx][ny] = map[a][b];
				
				q.push({nx, ny});
			}
		}
		
		if(flag) break;
		
		time += 1;
	}
	
	cout << map[x][y] << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> map[i][j];
			
			if(map[i][j] != 0)
				q.push({i, j});
		}
	}
	
	cin >> s >> x >> y;
	
	solve();
	
	return 0;
}
