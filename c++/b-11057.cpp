#include <iostream>
#include <cmath>

using namespace std;

long long int dp[1001][10] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	dp[0][9] = 1;
	for (int i = 1; i <= n; i++) {
		long long int sum = 0;
		for (int j = 0; j <= 9; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][9];
			else dp[i][j] = dp[i][j - 1] - dp[i - 1][j - 1];
			sum += dp[i][j];
		}
		dp[i][9] = sum % 10007;
	}

	int ans = (dp[n][9] < 0) ? 10007 + dp[n][9] : dp[n][9];
	
	cout << ans << '\n';

	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}*/

	return 0;
}