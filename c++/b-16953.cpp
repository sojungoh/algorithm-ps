#include <iostream>
#include <algorithm>

using namespace std;

int a, b;

void solve() {
	int ans = 1;

	while (a < b) {
		if (b % 10 == 1) {
			b = (b - 1) / 10;
			ans++;
			continue;
		}

		if (b % 2 == 1) {
			ans = -1;
			break;
		}
		b /= 2;
		ans++;
	}

	if (a > b)
		ans = -1;

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> a >> b;

	solve();

	return 0;
}