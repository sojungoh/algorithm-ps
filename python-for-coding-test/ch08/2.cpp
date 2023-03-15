#include <iostream>
#include <cmath>

using namespace std;

int ans; 
int dp[30001] = {0, };
int memo[30001] = {0, };

void bottom_up(int x) {
	
	for(int i = 2; i <= x; ++i) {
		
		dp[i] = dp[i - 1] + 1;
		
		if(i % 5 == 0)
			dp[i] = min(dp[i / 5] + 1, dp[i]);
		if(i % 3 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i]); 
		if(i % 2 == 0)
			dp[i] = min(dp[i / 2] + 1, dp[i]);
	}
	
	ans = dp[x];
}

int top_down(int x) {
	
	// termination
	if(x == 1)
		return 0;
	
	// already solved
	if(memo[x])
		return memo[x];
		
	memo[x] = top_down(x - 1) + 1;
	
	if(x % 5 == 0)
		memo[x] = min(top_down(x / 5) + 1, memo[x]);
	if(x % 3 == 0)
		memo[x] = min(top_down(x / 3) + 1, memo[x]);
	if(x % 2 == 0)
		memo[x] = min(top_down(x / 2) + 1, memo[x]);
	
	return memo[x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int x;
	cin >> x;
	
	bottom_up(x);
	
	cout << ans << endl;
	
	cout << top_down(x) << endl;
	
	return 0;
	
}
