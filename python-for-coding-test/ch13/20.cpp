#include <iostream>
#include <vector>

using namespace std;

int n; 
char map[7][7], visited[7][7] = {0, };
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
vector<pair<int, int>> t_coord, o_coord;

bool simulate() {
	bool flag = false;
	
	for(pair<int, int> p : o_coord)
		map[p.first][p.second] = 'O';
	
	for(pair<int, int> p : t_coord) {	
		for(int i = 0; i < 4; ++i) {
			int nx = p.first;
			int ny = p.second;
			
			while(true) {
				nx += dx[i];
				ny += dy[i];
				
				if(nx < 1 || ny < 1 || nx > n || ny > n)
					break;
				
				if(map[nx][ny] == 'O')
					break;
				
				if(map[nx][ny] == 'S') {
					flag = true;
					break;
				}
			}
			
			if(flag)
				break;
		}
		
		if(flag)
			break;
	}
	
	for(pair<int, int> p : o_coord)
		map[p.first][p.second] = 'X';
	
	return flag;
}

bool solve(int x, int y) {
	
	if(o_coord.size() == 3) {
		return simulate();
	}
	
	for(int i = x; i <= n; ++i) {
		for(int j = y; j <= n; ++j) {
			
			if(visited[i][j])
				continue;
			
			if(map[i][j] != 'X')
				continue;
			
			visited[i][j] = 1;
			o_coord.push_back({i, j});
			
			bool flag = solve(i, j + 1);
			
			if(!flag)
				return flag;
			
			visited[i][j] = 0;
			o_coord.pop_back();
		}
		y = 1;
	}
	
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> map[i][j];
			
			if(map[i][j] == 'T')
				t_coord.push_back({i, j});
		}
	}
	
	bool flag = solve(1, 1);
	
	if(flag)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	
	return 0;
}
