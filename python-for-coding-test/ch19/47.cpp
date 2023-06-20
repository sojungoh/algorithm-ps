#include <iostream>
#include <queue>

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

struct Graph {
	int g[4][4];
	
	Info(int[][4] _g):
		g(_g)
	{};
};

struct Compare {
	bool operator(const Info& a, const Info& b) {
		return a.num > b.num;
	}
};

void move_fish(int& arr[][4][2]) {
	priority_queue<Info, vector<Info>, Compare> pq;
	
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			pq.push(Info(i, j, arr[i][j][0], arr[i][j][1]));
	
	
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
			arr[nx][ny][1] = d;
			
			break;
		}
	}	
}

void solve(int graph[][4][2]) {
	queue<Graph> q;
	
	graph[0][0][0] = 0;
	move_fish(graph);
	
	int nx = 0;
	int ny = 0;
	while(true) {
		nx += dx[graph[0][0][1]];
		ny += + dy[graph[0][0][1]];
		
		if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
			break;
			
		q.push(nx, ny);
	}
	
	int dist[4][4];
	fill(&dist[0][0], &dist[3][4], 17);
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		if(dist[x][y] < graph[x][y])
			continue;
		
		dist[x][y] = graph[x][y];
		int temp[4][4][2] = graph;
		temp[x][y]
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[4][4][2];
	
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			cin >> arr[i][j][0] >> arr[i][j][1];
		}
	}
	
	
	
	return 0;
}
