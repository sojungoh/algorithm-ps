#include <iostream>
#include <algorithm>

using namespace std;

int arr[11] = {0, };

void solve(int n, int k) {
	
	int ans = 0;
	
	for(int i = 1; i <= k; ++i) {
		n -= arr[i];
		ans += n * arr[i];
	}
	
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, k, m;
	cin >> n >> k;
	
	for(int i = 0; i < n; ++i) {
		cin >> m;
		arr[m] += 1;
	}
	
	solve(n, k);
	
	return 0;
}
