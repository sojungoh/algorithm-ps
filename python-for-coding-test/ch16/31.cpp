#include <iostream>
#include <cmath>

using namespace std;

void solve() {
	
	int map[20][20], dp[20][20] = {0, };
	
	int n, m, ans = 0;
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> map[i][j];
			
			if(j == 0)
				dp[i][j] = map[i][j];
		}
	}
	
	for(int j = 1; j < m; ++j) {
		for(int i = 0; i < n; ++i) {
			
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + map[i][j]);
			
			if(i != 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + map[i][j]);
			if(i != n - 1)
			dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + map[i][j]);			
		}
	}
	
	for(int i = 0; i < n; ++i)
		ans = max(ans, dp[i][m - 1]);
	
	cout << ans << endl;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	 int t;
	 cin >> t;
	 
	 while(t--)
		solve();
	
	return 0;
}
