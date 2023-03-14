#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m, k, parent[2001] = { 0, };
vector<int> power;
priority_queue<tuple<int, int, int>> min_heap;

int find_parent(int x) {
	if (parent[x] != x)
		parent[x] = find_parent(parent[x]);
	return parent[x];
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

void kruskal() {
	int ans = 0;

	while (!min_heap.empty()) {
		int cost = -get<0>(min_heap.top());
		int a = get<1>(min_heap.top());
		int b = get<2>(min_heap.top());
		min_heap.pop();

		int parent_a = find_parent(a);
		int parent_b = find_parent(b);

		if (parent_a != parent_b) {
			if (parent_a < 1001 && parent_b < 1001)
				continue;
			union_parent(a, b);
			ans += cost;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		parent[1000 + i] = 1000 + i;
	
	for (int i = 0; i < k; i++) {
		int p;
		cin >> p;
		power.push_back(p);
		parent[p] = p;
	}

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		for (int j = 0; j < k; j++) {
			if (u == power[j])
				u -= 1000;

			if (v == power[j])
				v -= 1000;
		}

		min_heap.push({ -w, 1000 + u, 1000 + v });
	}

	kruskal();

	return 0;
}