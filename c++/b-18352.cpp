#include <iostream>
#include <vector>

using namespace std;

int n, m, k, x, visited[300001] = { 0, };
vector<pair<int, int>> map;

void solve() {
	for (int i = 0; i < m; i++) {
		if (map[i].first == x)
			visited[map[i].second] = 1;




	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k >> x;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map.push_back(make_pair(a, b));
	}

	solve();

	return 0;
}