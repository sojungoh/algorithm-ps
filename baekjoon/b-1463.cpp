#include <iostream>
#include <cmath>

using namespace std;

int ans; 
int dp[1000001] = {0, };

void bottom_up(int x) {
    
	for(int i = 2; i <= x; ++i) {
		
		dp[i] = dp[i - 1] + 1;
		
		// 6의 배수의 경우는 둘 다 비교해야 함
		if(i % 3 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i]); 
		if(i % 2 == 0)
			dp[i] = min(dp[i / 2] + 1, dp[i]);
	}
	
	ans = dp[x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int x;
	cin >> x;
	
	bottom_up(x);
	
	cout << ans << endl;
	
	return 0;
}

