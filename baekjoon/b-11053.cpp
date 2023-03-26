#include <iostream>
#include <cmath>

using namespace std;

int arr[1000], dp[1000];

void solve(int n) {
	
	int ans = 0;
	
	for(int i = 0; i < n; ++i)
		dp[i] = 1;
	
	for(int i = 1; i < n; ++i)
		for(int j = 0; j < i; ++j)
			if(arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
				
	for(int i = 0; i < n; ++i)
		ans = max(ans, dp[i]);
	
	cout << ans << endl;
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

