#include <iostream>

using namespace std;

int n, m, loc[3];
int map[50][50] = {0, };
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; // n w s e  -> counter clockwise

void solve() {
	
	int ans = 1;
	map[loc[0]][loc[1]] = 2;
	
	while(true) {
		
		int i, x, y;
		
		for(i = 0; i < 4; ++i) {
			loc[2] = (loc[2] != 3) ? loc[2] + 1 : 0;
			x = loc[0] + dx[loc[2]];
			y = loc[1] + dy[loc[2]];
			
			if(x < 0 || y < 0 || x >= n || y >= m)
				continue;
			
			if(map[x][y] != 0)
				continue;
			
			map[x][y] = 2;
			loc[0] = x;
			loc[1] = y;
			
			ans += 1;
			break;
		}
		
		if(i == 4) {
			loc[1] += 1;
			
			if(loc[1] < 1 || loc[1] > m || map[loc[0]][loc[1]] == 1)
				break;
		}
	}
	
	cout << ans << endl;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 0; i < 3; ++i)
		cin >> loc[i];
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> map[i][j];
	
	solve();
	
	return 0;
}
