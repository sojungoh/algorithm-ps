#include <iostream>
#include <algorithm>

using namespace std;

int n, l, a[1000];

void solve() {
	int ans = 1;
	int tape = a[0] + l;
	for (int i = 1; i < n; i++) {
		if (tape >= a[i] + 1)
			continue;
		ans++;
		tape = a[i] + l;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	solve();

	return 0;
}
