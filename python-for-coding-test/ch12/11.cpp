#include <iostream>
#include <queue>

using namespace std;

int map[101][101] = {0, };
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; // n w s e 

queue<pair<int, char>> snake_info;

void solve(int n) {
	
	int curr_x = 1, curr_y = 1, dir = 3;
	int time = 0;
	
	map[curr_x][curr_y] = 1;
	
	while(true) {
		
		int x = curr_x + dx[dir];
		int y = curr_y + dy[dir];
		
		if(x < 1 || y < 1 || x > n || y > n)
			break;
		
		if(map[x][y] == 1)
			break;
		
		if(map[x][y] != 2)
			map[curr_x][curr_y] = 0;
		
		map[x][y] = 1;
		
		curr_x = x;
		curr_y = y;
		time += 1;
		
		if(!snake_info.empty() && time == snake_info.front().first) {
			if(snake_info.front().second == 'L')
				dir = (dir == 3) ? 0 : dir + 1;
			else
				dir = (dir == 0) ? 3 : dir - 1;
			
			snake_info.pop();
		}
	}
	
	cout << time + 1 << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, k, l;
	
	cin >> n >> k;
	
	int x, y;
	for(int i = 0; i < k; ++i) {
		cin >> x >> y;
		map[x][y] = 2;
	}
	
	cin >> l;
	
	char c;
	for(int i = 0; i < l; ++i) {
		cin >> x >> c;
		snake_info.push({x, c});
	}
	
	solve(n);
	
	return 0;
}
