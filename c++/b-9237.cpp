#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100000];

bool cmp(int& a, int& b) {
	return a > b ? true : false;
}

void solve() {
	int ans, max = a[0];

	for (int i = 1; i < n; i++) {
		if (max < a[i] + i)
			max = a[i] + i;
	}
	ans = max + 2;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	swap(a[0], a[n - 1]);
	swap(a[0], a[n / 2]);
	sort(a, a + n, cmp);

	solve();

	return 0;
}