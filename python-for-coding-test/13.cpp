#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, m, map[51][51] = { 0, };
vector<pair<int, int>> ho;
vector<pair<int, int>> ch;

void solve() {
	vector<int> idx;

	for (int i = 0; i < ch.size() - m; i++)
		idx.push_back(0);
	for (int i = 0; i < m; i++)
		idx.push_back(1);

	int ans = 1000000;

	do {
		int temp = 0;

		for (int i = 0; i < ho.size(); i++) {
			int min_dist = 100;

			for (int j = 0; j < idx.size(); j++) {
				if (idx[j]) {
					int temp = abs(ch[j].first - ho[i].first) + abs(ch[j].second - ho[i].second);
					min_dist = min(temp, min_dist);
				}
			}
			temp += min_dist;
		}
		ans = min(temp, ans);

	} while (next_permutation(idx.begin(), idx.end()));
	
	cout << ans << '\n';
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				ho.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				ch.push_back(make_pair(i, j));
		}
	}

	solve();

	return 0;
}