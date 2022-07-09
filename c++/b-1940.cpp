#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[15000];

void solve() {
	int *front, *back, ans = 0;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);

	front = a; back = a + (n - 1);

	while (front < back) {
		while (m - *(front) < *back) back--;
		if (front != back && *(back) == m - *(front)) ans++;
		front++;
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	solve();

	return 0;
}