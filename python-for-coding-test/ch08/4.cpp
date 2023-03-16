#include <iostream>

using namespace std;

int dp[1001] = {0, };

void solve(int n) {
	
	dp[1] = 1;
	dp[2] = 3;
	
	// 나눗셈을 미리 해야 int 범위 초과 x
	for(int i = 3; i <= n; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 796796;
	
	cout << dp[n] << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	
	solve(n);
	
	return 0;
}
