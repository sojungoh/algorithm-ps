#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[5001][5001];

void solve(string a, string b) {
	
	long unsigned int i, j;
	
	for(i = 0; i <= a.length(); ++i)
		dp[i][0] = i;
	
	for(j = 0; j <= b.length(); ++j)
		dp[0][j] = j;
	
	for(i = 1; i <= a.length(); ++i) {
		for(j = 1; j <= b.length(); ++j) {
			
			if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
			
		}
	}
	
	cout << dp[a.length()][b.length()] << endl;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string a, b;
	
	cin >> a >> b;
	
	solve(a, b);

	return 0;
}
