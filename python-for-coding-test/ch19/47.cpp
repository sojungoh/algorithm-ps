#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

struct Info {
	int x;
	int y;
	int num;
	int dir;
	
	Info(int _x, int _y, int _num, int _dir):
		x(_x), y(_y), num(_num), dir(_dir)
	{};
};

struct Compare {
	bool operator()(const Info& a, const Info& b) {
		return a.num > b.num;
	}
};

void move_fish(int (*arr)[4][2]) {
	priority_queue<Info, vector<Info>, Compare> pq;
	
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			if(arr[i][j][0] <= 0)
				continue;
				
			pq.push(Info(i, j, arr[i][j][0], arr[i][j][1]));
		}
	}
	
	while(!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int n = pq.top().num;
		int d = pq.top().dir;
		
		pq.pop();
		
		for(int i = 0; i < 8; ++i) {
			int nx = x + dx[(d + i) % 8];
			int ny = y + dy[(d + i) % 8];
			
			if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
				continue;
			
			// shark is here
			if(arr[nx][ny][0] == 0)
				continue;
			
			arr[x][y][0] = arr[nx][ny][0];
			arr[x][y][1] = arr[nx][ny][1];
			arr[nx][ny][0] = n;
			arr[nx][ny][1] = (d + i) % 8;
			
			break;
		}
	}
}

int solve(int sum, int x, int y, int graph[4][4][2]) {
	queue<pair<int, int>> q;
	
	sum += graph[x][y][0];
	graph[x][y][0] = 0;
	
	move_fish(graph);
	
	cout << '\n';
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			cout << graph[i][j][0] << ' ' << graph[i][j][1] << '\t';
		}
		cout << '\n';
	}
	
	int nx = x;
	int ny = y;
	int dir = graph[x][y][1];
	
	while(true) {
		nx += dx[dir];
		ny += dy[dir];
		
		if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
			break;
		
		if(graph[nx][ny][0] == -1)
			continue;
		
		q.push({nx, ny});
	}
		
	int ret_val = sum;
	
	graph[x][y][0] = -1;
	
	while(!q.empty()) {
		nx = q.front().first;
		ny = q.front().second;
		
		q.pop();
		
		int tmp = solve(sum, nx, ny, graph);
		
		ret_val = max(ret_val, tmp);
	}
	
	graph[x][y][0] = 0;
	
	return ret_val;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[4][4][2];
	
	int dir;
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			cin >> arr[i][j][0] >> dir;
			arr[i][j][1] = dir - 1;
		}
	}
	
	cout << solve(0, 0, 0, arr) << '\n';
	
	return 0;
}
