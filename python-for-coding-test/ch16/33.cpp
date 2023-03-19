#include <iostream>
#include <cmath>

using namespace std;

int arr[16][2];
int dp[16] {0, };

void solve(int n) {
	
	int max_val = 0;
	
	for(int i = n; i > 0; --i) {
		
		int day = arr[i][0] + i;
		
		if(day > n + 1) {
			dp[i] = max_val;
			continue;
		}
		
		dp[i] = max(max_val, dp[day] + arr[i][1]);
		max_val = dp[i];
	}
	
	cout << max_val << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; ++i)
		cin >> arr[i][0] >> arr[i][1];
		
	solve(n);
	
	return 0;
}
