#include <iostream>
#include <cmath>

using namespace std;

int dp[1000];

void solve(int n) {
	
	dp[0] = 1;
	
	int i2 = 0, i3 = 0, i5 = 0;
	int v2 = 2, v3 = 3, v5 = 5;
	
	for(int i = 1; i < n; ++i) {
		dp[i] = min(min(v2, v3), v5);
		
		if(dp[i] == v2) {
			i2 += 1;
			v2 = dp[i2] * 2;
		}
		if(dp[i] == v3) {
			i3 += 1;
			v3 = dp[i3] * 3;
		}
		if(dp[i] == v5) {
			i5 += 1;
			v5 = dp[i5] * 5;
		}
	}
	
	cout << dp[n - 1] << endl;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	solve(n);
	
	return 0;
}
