#include <iostream>
#include <cmath>

using namespace std;

int arr[100], dp[100] = {0, };

void solve(int n) {
	
	dp[0] = arr[0];
	dp[1] = max(arr[0], arr[1]);
	
	for(int i = 2; i < n; ++i)
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
	
	cout << dp[n - 1] << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	
	solve(n);

	return 0;
}
