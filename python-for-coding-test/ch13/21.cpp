#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int N, L, R, map[50][50], visited[50][50];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

bool bfs(int a, int b) {
	int uni_sum = 0, uni_count = 0;
	queue<pair<int, int>> q;
	vector<pair<int, int>> uni;
	
	q.push({a, b});
	visited[a][b] = 1;
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		uni.push_back({x, y});
		uni_sum += map[x][y];
		uni_count++;
		
		for(int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			
			if(visited[nx][ny])
				continue;
			
			int diff = abs(map[x][y] - map[nx][ny]);
			
			if(L <= diff && diff <= R) {
				visited[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
	
	for(pair<int, int> p : uni)
		map[p.first][p.second] = uni_sum / uni_count;
	
	if(uni_count == 1)
		return false;
	return true;
}

void solve() {
	
	int ans = 0;
	
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(visited[i][j])
				continue;
			
			for(int m = 0; m < N; ++m)
				for(int n = 0; n < N; ++n)
					visited[m][n] = 0;
			
			if(bfs(i, j))
				ans += 1;
		}
	}
	
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> L >> R;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cin >> map[i][j];
	
	solve();
	
	return 0;
}
