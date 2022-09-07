#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, ans = 0;
vector<pair<int, int>> product;

void solve(int sz, int start, int value) {
	if (sz) {
		ans = max(ans, value);
		return;
	}

	for (int i = start; i < n; i++) {

	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		product.push_back({ w, v });
	}

	sort(product.begin(), product.end());

	for(int i = 1; i <= n; i++)
		solve(i, 0, 0);

	return 0;
}