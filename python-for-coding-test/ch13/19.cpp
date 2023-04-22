#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num[11], visited[10] = {0, };
int max_ans = -int(1e9), min_ans = int(1e9);
vector<int> sign, selected;

int calculate() {
	
	int res = num[0];
	
	for(int i = 0; i < n - 1; ++i) {
		if(selected[i] == 0)
			res += num[i + 1];
		else if(selected[i] == 1)
			res -= num[i + 1];
		else if(selected[i] == 2)
			res *= num[i + 1];
		else
			res /= num[i + 1];
	}
	
	return res;
}

void solve() {
	
	if(selected.size() == n - 1) {
		int res = calculate();
		max_ans = max(max_ans, res);
		min_ans = min(min_ans, res);
		
		return;
	}
	
	for(int i = 0; i < sign.size(); ++i) {
		
		if(visited[i])
			continue;
			
		visited[i] = 1;
		selected.push_back(sign[i]);
		
		solve();
		
		visited[i] = 0;
		selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	for(int i = 0; i < n; ++i)
		cin >> num[i];
	
	int j;
	for(int i = 0; i < 4; ++i) {
		cin >> j;
		
		while(j--) {
			sign.push_back(i);
		}
	}
	
	solve();
	
	cout << max_ans << endl;
	cout << min_ans << endl;
	
	return 0;
}
