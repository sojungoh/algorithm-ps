#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, arr[1000000];
vector<int> lis;

void solve() {
	for (int i = 0; i < n; i++) {
		int lb_idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();

		if (lb_idx == lis.size()) {
			lis.push_back(arr[i]);
		}
		else {
			lis[lb_idx] = arr[i];
		}
	}

	cout << lis.size() << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	solve();

	return 0;
}