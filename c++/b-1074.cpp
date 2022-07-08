#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, n, r, c;

int recursive() {
	if (n == 1)
		return 2 * r + c;
	else {
		int k = 0;
		if (r >= pow(2, n - 1)) {
			r -= pow(2, n - 1);
			k += 2;
		}
		if (c >= pow(2, n - 1)) {
			c -= pow(2, n - 1);
			k += 1;
		}
		n--;
		return k * pow(4, n) + recursive();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans;
	cin >> N >> r >> c;
	n = N;
	ans = recursive();
	
	cout << ans << "\n";

	return 0;
}