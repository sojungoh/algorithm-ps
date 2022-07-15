#include <iostream>
#include <algorithm>

using namespace std;

int n, a[30000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans = -1, temp = 0, h = a[0];
	for (int i = 1; i < n; i++) {
		if (h > a[i]) temp++;
		else {
			ans = max(temp, ans);
			h = a[i];
			temp = 0;
		}
	}
	ans = max(temp, ans);

	cout << ans << '\n';

	return 0;
}