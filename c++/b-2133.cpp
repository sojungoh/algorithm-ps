#include <iostream>

using namespace std;

int dp[16], ans = 0;

void solve(int n) {

	int k = n / 2;

	dp[0] = 1;
	dp[1] = 3;

	for (int i = 2; i <= k; i++) {

		dp[i] = dp[i - 1] * dp[1];

		for (int j = i - 2; j >= 0; j--) {
			dp[i] += dp[j] * 2;
		}
	}

	ans = dp[k];

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	if (n % 2 == 1)
		ans = 0;
	else
		solve(n);

	cout << ans << '\n';

	return 0;
}