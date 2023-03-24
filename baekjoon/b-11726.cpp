#include <iostream>
#include <cmath>

using namespace std;

int dp[1001];

void solve(int n) {
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	
	for(int i = 4; i <= n; ++i)
		dp[i] = (dp[i - 1] * 2) % 10007;
	
	cout << dp[n] << endl;
}

int main() {
	
	int n;
	cin >> n;
	
	solve(n);
	
	return 0;
}
