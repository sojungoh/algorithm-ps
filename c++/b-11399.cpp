#include <iostream>
#include <algorithm>

using namespace std;

int n, p[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> p[i];

	sort(p, p + n);

	for (int i = 0; i < n; i++)
		ans += p[i] * (n - i);

	cout << ans << '\n';

	return 0;
}