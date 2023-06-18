#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

struct Shark {
	int x;
	int y;
	int time;
	int fish;
	int length;
	
	Shark(int _x, int _y, int _time, int _fish, int _length) :
		x(_x), y(_y), time(_time), fish(_fish), length(_length)
	{};
};

int main() {
	ios::sync_with_stdio(0);
	
	int n;	
	cin >> n;
	
	int arr[20][20];
	
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
	
	Shark shark(a, b, 0, 0, 2);
	
	while(true) {
		int visited[20][20] = {0, };
		queue<Shark> q;
		q.push(Shark(shark.x, shark.y, shark.time, shark.fish, shark.length));
		visited[shark.x][shark.y] = 1;
		
		int min_time = 0;
		bool flag = false;
		
		while(!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int t = q.front().time;
			
			q.pop();
			
			if(t > min_time)
				break;
			
			for(int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;
				
				if(visited[nx][ny] || arr[nx][ny] > shark.length)
					continue;
				
				if(0 < arr[nx][ny] && arr[nx][ny] < shark.length) {
					shark.x = nx;
					shark.y = ny;
					shark.time = t + 1;
					min_time = t + 1;
					shark.fish += 1;
					arr[nx][ny] = 0;
					flag = true;
					
					if(shark.fish == shark.length) {
						shark.fish = 0;
						shark.length += 1;
					}
				}
				
				visited[nx][ny] = 1;
				q.push(Shark(nx, ny, t + 1, shark.fish, shark.length)); 
			}
			
			
		}
		
		if(!flag && q.empty())
			break;
	}
	
	cout << shark.time << '\n';
	
	return 0;
}
