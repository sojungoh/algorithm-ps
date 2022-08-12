#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int n, parent[100000];;
vector<pair<int, int>> p_coord[3];
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
	int ans = 0, p_count = 0;

	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n - 1; j++) {
				int cost = abs(p_coord[i][j].first - p_coord[i][j + 1].first);
				min_heap.push({ -cost, p_coord[i][j].second, p_coord[i][j + 1].second });
		}
	}

	while (!min_heap.empty()) {
		int cost = -get<0>(min_heap.top());
		int a = get<1>(min_heap.top());
		int b = get<2>(min_heap.top());
		min_heap.pop();

		if (find_parent(a) != find_parent(b)) {
			union_parent(a, b);
			ans += cost;
			p_count++;
		}

		if (p_count == n - 1)
			break;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		p_coord[0].push_back({ x, i });
		p_coord[1].push_back({ y, i });
		p_coord[2].push_back({ z, i });
	}

	for (int i = 0; i < 3; i++)
		sort(p_coord[i].begin(), p_coord[i].end());

	kruskal();

	/*for (int i = 0; i < n; i++) {
		cout << "cost: " << min_cost[i] << ' ';
		cout << "(" << min_edge[i][0] << " , " << min_edge[i][1] << ")" << '\n';
	}*/

	return 0;
}