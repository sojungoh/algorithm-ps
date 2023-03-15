#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[1000], ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	// 1 2 2 3 3 => 1�� 4��, 2�� 2x2=4��, 3�� x
	// 1 2 2 3 4 4 5 5 => 1�� 7��, 2�� 5x2=10��, 3�� 4��, 4�� 2x2=4��, 5�� x

	int k = 1;
	for (int i = 0; i < n - 1; i++) {

		if (a[i] == a[i + 1]) {
			k++;
			continue;
		}

		ans += k * (n - (i + 1));
		k = 1;
	}

	cout << ans << '\n';

	return 0;
}