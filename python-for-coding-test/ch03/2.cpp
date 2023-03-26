#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
int arr[1000];

void solve() {
	
	sort(arr, arr + n);
	
	int q = m / (k + 1);
	int r = m % (k + 1);
	
	int ans = (q + r) * k * arr[n - 1] + q * arr[n - 2];
	
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	
	solve();
	
	return 0;
}
