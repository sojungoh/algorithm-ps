#include <iostream>

using namespace std;

int n, A[1000], dp[1000][2], ans = 0;

void solve() {

	// increasing
	for (int i = 0; i < n; i++) {
		
		dp[i][0] = 1;

		for (int j = 0; j < i; j++) {
			if (A[j] < A[i] && dp[i][0] < dp[j][0] + 1)
				dp[i][0] = dp[j][0] + 1;
		}
	}

	// decreasing
	for (int i = n - 1; i >= 0; i--) {

		dp[i][1] = 1;

		for (int j = n - 1; j > i; j--) {
			if (A[j] < A[i] && dp[i][1] < dp[j][1] + 1)
				dp[i][1] = dp[j][1] + 1;
		}
	}

	// result
	for (int i = 0; i < n; i++)
		if (dp[i][0] + dp[i][1] > ans)
			ans = dp[i][0] + dp[i][1];

	ans -= 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	solve();

	cout << ans << '\n';

	return 0;
}