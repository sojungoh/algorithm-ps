#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100000];

void solve() {
	int i = 0, count = 1, ans = 0;

	do {
		if (count == a[i]) {
			ans++;
			count = 1;
		}
		else count++;
		
		i++;
	} while (i < n);

	cout << ans << '\n';
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	solve();

	return 0;
}