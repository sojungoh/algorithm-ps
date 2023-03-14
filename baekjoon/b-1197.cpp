#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int v, e, parent[10001];
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
	int ans = 0, e_count = 0;

	for (int i = 1; i <= v; i++)
		parent[i] = i;

	while (!min_heap.empty()) {
		int cost = -get<0>(min_heap.top());
		int a = get<1>(min_heap.top());
		int b = get<2>(min_heap.top());
		min_heap.pop();

		if (find_parent(a) != find_parent(b)) {
			union_parent(a, b);
			e_count++;
			ans += cost;
		}
		if (e_count == v - 1)
			break;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		min_heap.push({ -c, a, b });
	}

	kruskal();

	return 0;
}