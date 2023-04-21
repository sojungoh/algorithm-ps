#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, k, s, x, y, map[201][201];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
priority_queue<tuple<int, int, int>> pq;

void solve() {
	
	int time = 0;
	
	while(!pq.empty()) {
		
		bool flag = false;
		size_t sz = pq.size();
		priority_queue<tuple<int, int, int>> tmp;
		
		if(time == s)
			break;
		
		for(size_t t = 0; t < sz; ++t) {
			
			int virus = -get<0>(pq.top());
			int a = get<1>(pq.top());
			int b = get<2>(pq.top());
		
			pq.pop();
			
			if(a == x && b == y) {
				flag = true;
				break;
			}
			
			for(int i = 0; i < 4; ++i) {
				int nx = a + dx[i];
				int ny = b + dy[i];
				
				if(nx < 1 || ny < 1 || nx > n || ny > n)
					continue;
				
				if(map[nx][ny] != 0)
					continue;
				
				map[nx][ny] = virus;
				
				tmp.push({-virus, nx, ny});
			}
		}
		
		if(flag) break;
		
		time += 1;
		
		pq = tmp;
	}
	
	cout << map[x][y] << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> map[i][j];
			
			if(map[i][j] != 0)
				pq.push({-map[i][j], i, j});
		}
	}
	
	cin >> s >> x >> y;
	
	solve();
	
	return 0;
}
