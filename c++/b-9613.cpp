#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
	int n, input;
	long long ans = 0;
	vector<int> gcd;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		gcd.push_back(input);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int max_num = max(gcd[i], gcd[j]);
			int min_num = min(gcd[i], gcd[j]);

			if (max_num % min_num == 0) {
				ans += min_num;
				continue;
			}

			int k = min_num;

			do {
				--k;
			} while (min_num % k != 0 || max_num % k != 0);

			ans += k;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
		solve();

	return 0;
}