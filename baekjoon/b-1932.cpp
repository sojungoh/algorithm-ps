#include <iostream>
#include <cmath>

using namespace std;

int arr[500][500], dp[500][500] = {0, };

void solve(int n) {
	
	dp[0][0] = arr[0][0];
	
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
				
			if(j != 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i][j]);
			if(j != i)
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]); 
			
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; ++i)
		ans = max(ans, dp[n - 1][i]);
		
	cout << ans << endl;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j <= i; ++j)
			cin >> arr[i][j];
			
	solve(n);
	
	return 0;
}
