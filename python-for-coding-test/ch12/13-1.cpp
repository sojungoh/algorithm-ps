#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 1301, map[51][51] = {0, };
vector<pair<int, int>> chicken_coord, house_coord;
vector<int> idx;

int get_chicken_dist() {
	
	int ret_val = 0;
	
	for(pair<int, int> p : house_coord) {
		
		int min_val = 1301;
		
		for(int i : idx) {
			int temp = 0;
			
			temp += abs(p.first - chicken_coord[i].first);
			temp += abs(p.second - chicken_coord[i].second);
			
			min_val = min(min_val, temp);
		}
		
		ret_val += min_val;
	}
	
	return ret_val;
}

void solve(int k) {
		
	if(idx.size() == m) {
			
		ans = min(ans, get_chicken_dist());
		
		return;
	}
	
	for(size_t i = k; i < chicken_coord.size(); ++i) {
		
		idx.push_back(i);
		
		solve(i + 1);
		
		idx.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> map[i][j];
			
			if(map[i][j] == 1)
				house_coord.push_back({i, j});
			
			if(map[i][j] == 2)
				chicken_coord.push_back({i, j});
		}
	}
	
	solve(0);
	
	cout << ans << endl;
	
	return 0;
}
