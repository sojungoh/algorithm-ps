#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

int n, visited[101] = { 0, }, parent[101];
float star_coord[101][2];
priority_queue<tuple<float, int, int>> min_heap;
vector<int> stars;

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

void dfs(int curr) {
	if (stars.size() == 2) {
		float dx = star_coord[stars[0]][0] - star_coord[stars[1]][0];
		float dy = star_coord[stars[0]][1] - star_coord[stars[1]][1];
		float cost = sqrt(pow(dx, 2) + pow(dy, 2));

		min_heap.push({ -cost, stars[0], stars[1] });

		return;
	}
	
	for (int i = curr; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		stars.push_back(i);
		dfs(i + 1);
		visited[i] = 0;
		stars.pop_back();
	}
}

void solve() {
	int star_count = 0;
	float ans = 0.0;
	dfs(1);

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	while (!min_heap.empty()) {
		float dist = -get<0>(min_heap.top());
		int a = get<1>(min_heap.top());
		int b = get<2>(min_heap.top());
		min_heap.pop();

		if (find_parent(a) != find_parent(b)) {
			union_parent(a, b);
			star_count++;
			ans += dist;
		}

		if (star_count == n - 1) break;
	}

	printf("%.2f", ans);
}

int main() {
	//ios::sync_with_stdio(0);	
	//cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		scanf("%f %f", &star_coord[i][0], &star_coord[i][1]);

	solve();

	return 0;
}