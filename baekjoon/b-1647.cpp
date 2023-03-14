#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m, village[100001];
priority_queue<tuple<int, int, int>> min_heap;

int find_village(int x) {
	if (village[x] != x)
		village[x] = find_village(village[x]);
	return village[x];
}

void union_village(int a, int b) {
	a = find_village(a);
	b = find_village(b);

	if (a < b)
		village[b] = a;
	else
		village[a] = b;
}

void solve() {
	int ans = 0, e_count = 0;

	for (int i = 1; i <= n; i++)
		village[i] = i;

	while (!min_heap.empty()) {
		int cost = -get<0>(min_heap.top());
		int a = get<1>(min_heap.top());
		int b = get<2>(min_heap.top());
		min_heap.pop();

		if (find_village(a) != find_village(b)) {
			union_village(a, b);
			ans += cost;
			e_count++;
		}

		if (e_count == n - 1) {
			ans -= cost;
			break;
		}
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		min_heap.push({ -c, a, b });
	}

	solve();
		
	return 0;
}