#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int m, n, parent[200000];

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

void solve() {
	int total_cost = 0, min_cost = 0;
	priority_queue<tuple<int, int, int>> min_heap;

	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		total_cost += z;
		min_heap.push({ -z, x, y });
	}

	while (!min_heap.empty()) {
		int dist = -get<0>(min_heap.top());
		int a = get<1>(min_heap.top());
		int b = get<2>(min_heap.top());
		min_heap.pop();

		if (find_parent(a) != find_parent(b)) {
			union_parent(a, b);
			min_cost += dist;
		}
	}

	cout << total_cost - min_cost << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;

	while (m != 0 && n != 0) {
		solve();
		cin >> m >> n;
	}

	return 0;
}