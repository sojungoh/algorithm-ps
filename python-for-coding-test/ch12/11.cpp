#include <iostream>
#include <vector>

using namespace std;

int map[101][101] = {0, };
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; 

vector<pair<int, char>> snake_info;

void solve(int n) {
	
	int h_time = 0, t_time = 0, h_idx = 0, t_idx = 0;
	int head_info[3] = {1, 1, 3};
	int tail_info[3] = {1, 1, 3};
	
	map[1][1] = 1;
	
	while(true) {
		
		int x = head_info[0] + dx[head_info[2]];
		int y = head_info[1] + dy[head_info[2]];
		
		if(x < 1 || y < 1 || x > n || y > n)
			break;
		
		if(map[x][y] == 1)
			break;
		
		if(map[x][y] != 2) {
			map[tail_info[0]][tail_info[1]] = 0;
			tail_info[0] += dx[tail_info[2]];	
			tail_info[1] += dy[tail_info[2]];
			t_time += 1;
		}
		
		map[x][y] = 1;
		
		head_info[0] = x;
		head_info[1] = y;
		h_time += 1;
		
		if(h_idx < snake_info.size()) {
			if(h_time == snake_info[h_idx].first) {
				if(snake_info[h_idx].second == 'L')
					head_info[2] = (head_info[2] == 3) ? 0 : head_info[2] + 1;
				else
					head_info[2] = (head_info[2] == 0) ? 3 : head_info[2] - 1;
				
				h_idx += 1;
			}
		}
		
		if(t_idx < snake_info.size()) {
			if(t_time == snake_info[t_idx].first) {
				if(snake_info[t_idx].second == 'L')
					tail_info[2] = (tail_info[2] == 3) ? 0 : tail_info[2] + 1;
				else
					tail_info[2] = (tail_info[2] == 0) ? 3 : tail_info[2] - 1;
					
				t_idx += 1;
			}
		}
	}
	
	cout << h_time + 1 << endl;
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
		snake_info.push_back({x, c});
	}
	
	solve(n);
	
	return 0;
}
