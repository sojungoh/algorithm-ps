#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, indegree[32001] = { 0, };
vector<int> height[32001];

void topology_sort() {
	vector<int> ans;
	queue<int> q;

	for (int i = 1; i <= n; i++)
		if (!indegree[i]) q.push(i);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		ans.push_back(curr);

		for (int i = 0; i < height[curr].size(); i++) {
			int next = height[curr][i];
			indegree[next] -= 1;

			if (!indegree[next]) q.push(next);
		}
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		height[a].push_back(b);
		indegree[b]++;
	}

	topology_sort();

	return 0;
}