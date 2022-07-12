#include <iostream>
#include <algorithm>

using namespace std;

int n, k, a[10];

void solve() {
	int ans = 0;

	while (k > 0) {
		if (a[--n] > k)
			continue;

		ans += k / a[n];
		k %= a[n];
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	solve();

	return 0;
}