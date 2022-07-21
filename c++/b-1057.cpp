#include <iostream>
#include <cmath>

using namespace std;

int n, k_num, i_num, ans = 1;

void solve() {
	int max_num = max(k_num, i_num), min_num = min(k_num, i_num);

	while (1) {
		if (max_num == 1) {
			ans = -1;
			break;
		}

		if (max_num % 2 == 0 && max_num - min_num == 1) 
			break;

		if (min_num != 1)
			min_num = (min_num % 2 == 1) ? (min_num + 1) / 2 : min_num / 2;

		max_num = (max_num % 2 == 1) ? (max_num + 1) / 2 : max_num / 2;
		
		++ans;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k_num >> i_num;

	solve();

	return 0;
}