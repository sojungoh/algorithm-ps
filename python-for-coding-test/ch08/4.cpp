#include <iostream>
#include <cmath>

using namespace std;

int dp[1001] = {0, };

void solve(int n) {
	
	dp[1] = 1;
	dp[2] = 3;
	
	for(int i = 3; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
	
	cout << dp[n] % 796796 << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	solve(n);
	
	return 0;
}
