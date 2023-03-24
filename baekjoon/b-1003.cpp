#include <iostream>

using namespace std;

int dp[41][2];

void solve() {
	
	int n;
	cin >> n;
	
	dp[0][0] = 1; dp[0][1] = 0;
	dp[1][0] = 0; dp[1][1] = 1;
	
	for(int i = 2; i <= n; ++i) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
	
	cout << dp[n][0] << ' ' << dp[n][1] << endl;
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
