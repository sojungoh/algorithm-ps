#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int map[51][51] = {0, };
vector<pair<int, int>> chicken_coord, house_coord;

int get_chicken_dist(vector<int> comb) {
	
	int ret_val = 0;
	
	for(pair<int, int> p : house_coord) {
		
		int min_val = int(1e9);
		
		for(int idx : comb) {
			int temp = 0;
			temp += abs(p.first - chicken_coord[idx].first);
			temp += abs(p.second - chicken_coord[idx].second);
			
			min_val = min(min_val, temp);
		}
		
		ret_val += min_val;
	}
	
	return ret_val;
}

void solve() {
	
	int answer = int(1e9);
	int sz = chicken_coord.size();
	
	vector<int> v1;
	vector<bool> v2;
	
	for(int i = 0; i < sz; ++i)
		v1.push_back(i);
	
	for(int i = 0; i < m; ++i)
		v2.push_back(true);
		
	for(int i = 0; i < sz - m; ++i)
		v2.push_back(false);
	
	do {
		
		vector<int> comb;
		
		for(int i = 0; i < sz; ++i)		
			if(v2[i])
				comb.push_back(v1[i]);
		
		answer = min(answer, get_chicken_dist(comb));
		
	}while(prev_permutation(v2.begin(), v2.end()));
	
	cout << answer << endl;
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
	
	solve();
	
	return 0;
}
