#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, k, coin[100], dp[10001];

void solve() {

	dp[0] = 0;
	
	sort(coin, coin + n);

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == 10001)
		cout << -1 << '\n';
	else
		cout << dp[k] << '\n';

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int i = 0; i <= k; i++)
		dp[i] = 10001;

	solve();

	return 0;
}