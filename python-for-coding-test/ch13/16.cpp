#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, map[8][8];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
vector<pair<int, int>> empty_coord, virus_coord;

int get_safe_size(vector<pair<int, int>> tmp_wall) {
	
	int tmp_map[n][m], ret_val = 0;
	queue<pair<int, int>> q;
	
	// copy the map
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			tmp_map[i][j] = map[i][j];
	
	// install three walls
	for(pair<int, int> p : tmp_wall)
		tmp_map[p.first][p.second] = 1;
	
	// spread the viruses
	for(pair<int, int> p : virus_coord)
		q.push({p.first, p.second});
	
	while(!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		for(int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			
			if(tmp_map[nx][ny] == 0) {
				tmp_map[nx][ny] = 2;
				q.push({nx, ny});
			}
		}
	}
	
	// check a safe zone size
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(tmp_map[i][j] == 0)
				ret_val += 1;
	
	return ret_val;
}

void solve() {
	
	int answer = 0;
	vector<int> index;
	size_t sz = empty_coord.size();
	
	for(int i = 0; i < 3; ++i)
		index.push_back(0);
	for(size_t i = 0; i < sz - 3; ++i)
		index.push_back(1);
	
	do {
		
		vector<pair<int, int>> tmp_wall;
		
		for(size_t i = 0; i < sz; ++i)
			if(index[i] == 0)
				tmp_wall.push_back({empty_coord[i].first, empty_coord[i].second});
		
		answer = max(answer, get_safe_size(tmp_wall));
		
	}while(next_permutation(index.begin(), index.end()));
	
	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) { 
			cin >> map[i][j];
			
			if(map[i][j] == 0)
				empty_coord.push_back({i, j});
			else if(map[i][j] == 2)
				virus_coord.push_back({i, j});
		}
	}
	
	solve();
	
	return 0;
}
