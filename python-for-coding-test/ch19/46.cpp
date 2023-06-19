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
	cin.tie(0);
	
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
			}
		}
	}
	
	Shark shark(a, b, 0, 0, 2);
	
	while(true) {
		int visited[20][20] = {0, };
		queue<Shark> q;
		q.push(Shark(shark.x, shark.y, shark.time, shark.fish, shark.length));
		arr[shark.x][shark.y] = 0;
		visited[shark.x][shark.y] = 1;
		
		bool flag = false;
		Shark temp(n, n, int(1e9), shark.fish, shark.length);
		
		while(!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int t = q.front().time;
			int f = q.front().fish;
			int l = q.front().length;
			
			q.pop();
			
			if(flag && temp.time < t) {
				shark = temp;
				break;
			}
			
			for(int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;
				
				if(visited[nx][ny] || arr[nx][ny] > l)
					continue;
						
				visited[nx][ny] = 1;
				
				if(0 < arr[nx][ny] && arr[nx][ny] < l) {
					flag = true;
					
					if(temp.x < nx)
						continue;
					
					if(temp.x == nx && temp.y < ny)
						continue;
					
					temp.x = nx;
					temp.y = ny;
					temp.time = t + 1;
					f++;
					temp.fish = f;
					
					if(temp.fish == l) {
						f = 0;
						temp.fish = f;
						l++;
						temp.length = l;
					}
				}
				
				q.push(Shark(nx, ny, t + 1, f, l)); 
			}
			
			if(flag)
				break;
		}
		
		cout << '\n';
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		
		if(!flag)
			break;
	}
	
	cout << shark.time << '\n';
	
	return 0;
}
