#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, edges[201][201], parent[201];
vector<int> plans;

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
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!edges[i][j]) continue;

			if (find_parent(i) != find_parent(j))
				union_parent(i, j);
		}
	}

	bool flag = true;
	int p = parent[plans[0]];

	for (int check : plans) {
		if (p != parent[check]) {
			flag = false;
			break;
		}
	}
	
	if (flag)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> edges[i][j];

	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		plans.push_back(p);
	}

	kruskal();

	return 0;
}