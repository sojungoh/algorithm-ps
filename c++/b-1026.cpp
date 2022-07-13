#include <iostream>
#include <algorithm>

using namespace std;

int n, a[50], b[50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a, a + n);
	sort(b, b + n);

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += a[i - 1] * b[n - i];
	}

	cout << ans << '\n';

	return 0;
}