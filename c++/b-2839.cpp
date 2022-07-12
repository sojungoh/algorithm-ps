#include <iostream>
#include <algorithm>

using namespace std;

int n;

void solve() {
	int ans = -1;

	if (n % 5 == 0)
		ans = n / 5;
	else {
		int count = 1;
		int num = n;

		while (3 <= num) {
			num -= 3;
			if (num % 5 == 0) {
				ans = count + num / 5;
				break;
			}
			count++;
		}
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	solve();

	return 0;
}