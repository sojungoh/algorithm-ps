#include <iostream>
#include <cmath>

using namespace std;

int dp[10001], arr[100];

void solve(int n, int m) {
	
	dp[0] = 0;
	
	for(int i = 1; i <= 10000; ++i)
		dp[i] = 10001;
	
	for(int i = 0; i < n; ++i)
		for(int j = arr[i]; j <= m; ++j)
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
	
	int ans = (dp[m] == 10001) ? -1 : dp[m];
	
	cout << ans << endl;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	
	solve(n, m);
	
	return 0;
}
