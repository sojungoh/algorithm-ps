#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

struct Info {
	int x;
	int y;
	int time;
	int fish;
	int length;
	
	Info(int _x, int _y, int _time, int _fish, int _length) :
		x(_x), y(_y), time(_time), fish(_fish), length(_length)
	{};
};

struct compare {
	bool operator() (const Info& a, const Info& b) {
		if(a.time == b.time) {
			if(a.x == b.x)
				return a.y > b.y;
			return a.x > b.x;
		}
		return a.time > b.time;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;	
	cin >> n;
	
	int arr[n][n];
	
	int a, b;	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			
			if(arr[i][j] == 9) {
				a = i;
				b = j;
				arr[i][j] = 0;
			}
		}
	}
	
	Info sinfo(a, b, 0, 0, 2);
	
	while(true) {	
		bool visited[n][n] = {0, };
		priority_queue<Info, vector<Info>, compare> pq;
		pq.push(Info(sinfo.x, sinfo.y, sinfo.time, sinfo.fish, sinfo.length));
		visited[sinfo.x][sinfo.y] = 1;
		
		while(!pq.empty()) {
			int x = pq.top().x;
			int y = pq.top().y;
			int t = pq.top().time;
			
			pq.pop();
			
			for(int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;
				
				if(visited[nx][ny] || arr[nx][ny] > sinfo.length)
					continue;
				
				if(0 < arr[nx][ny] && arr[nx][ny] < sinfo.length) {
					sinfo.x = nx;
					sinfo.y = ny;
					sinfo.time = t + 1;
					sinfo.fish += 1;
					arr[nx][ny] = 0;
					break;
				}
				
				visited[nx][ny] = 1;
				pq.push(Info(nx, ny, t + 1, sinfo.fish, sinfo.length)); 
			}
		}
		
		if(sinfo.fish == sinfo.length) {
			sinfo.fish = 0;
			sinfo.length += 1;
		}
		
		if(pq.empty())
			break;
	}
	
	cout << sinfo.time << '\n';
	
	return 0;
}
