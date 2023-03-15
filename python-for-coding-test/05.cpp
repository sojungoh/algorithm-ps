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

	// 1 2 2 3 3 => 1은 4개, 2는 2x2=4개, 3은 x
	// 1 2 2 3 4 4 5 5 => 1은 7개, 2는 5x2=10개, 3은 4개, 4는 2x2=4개, 5는 x

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