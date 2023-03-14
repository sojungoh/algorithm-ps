#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, cost[1000][3];

void solve() {
	vector<pair<int, int>> rgb;

	for (int i = 0; i < 3; i++)
		rgb.push_back({ cost[0][i], i });

	for (int i = 1; i < n; i++) {
		sort(rgb.begin(), rgb.end());

		int min_cost = rgb[0].first, min_idx = rgb[0].second;
		int mid_cost = rgb[1].first, mid_idx = rgb[1].second;

		for (int j = 0; j < 3; j++) {
			if (j == min_idx) {
				rgb[j].first = mid_cost + cost[i][j];
				rgb[j].second = j;
			}
			else {
				rgb[j].first = min_cost + cost[i][j];
				rgb[j].second = j;
			}
		}
	}

	sort(rgb.begin(), rgb.end());

	cout << rgb[0].first << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	solve();

	return 0;
}
