#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, indegree[501] = { 0, }, rank_map[501][501] = { 0, };

void topology_sort() {
	queue<int> q;
	vector<int> ans;

	for (int i = 1; i <= n; i++)
		if (!indegree[i]) q.push(i);

	while (!q.empty()) {

		if (q.size() != 1) {
			cout << "?" << '\n';
			return;
		}
			
		int curr = q.front();
		q.pop();
		ans.push_back(curr);

		for (int i = 1; i <= n; i++) {
			if (!rank_map[curr][i]) continue;
			indegree[i] -= 1;

			if (!indegree[i]) q.push(i);
		}
	}

	if (ans.size() != n)
		cout << "IMPOSSIBLE" << '\n';
	else {
		for (int out : ans)
			cout << out << ' ';
		cout << '\n';
	}
}

void solve() {
	vector<int> o_rank;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int ti;
		cin >> ti;
		o_rank.push_back(ti);
		indegree[ti] = i;
	}

	for (int i = 0; i < o_rank.size() - 1; i++)
		for (int j = i + 1; j < o_rank.size(); j++)
			rank_map[o_rank[i]][o_rank[j]] = 1;

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		if (rank_map[a][b] == 1) {
			rank_map[a][b] = 0;
			rank_map[b][a] = 1;
			indegree[a] += 1;
			indegree[b] -= 1;
		}
		else {
			rank_map[a][b] = 1;
			rank_map[b][a] = 0;
			indegree[a] -= 1;
			indegree[b] += 1;
 		}
	}

	topology_sort();

	memset(indegree, 0, sizeof(indegree));
	memset(rank_map, 0, sizeof(rank_map));

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}