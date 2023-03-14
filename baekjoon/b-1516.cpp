#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int n, indegree[501], c_time[501], ans[501] = { 0, };
vector<vector<int>> pre_class(501);
queue<int> q;

void solve() {
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < pre_class[curr].size(); i++) {
			int next = pre_class[curr][i];
			indegree[next] -= 1;

			ans[next] = max(ans[next], ans[curr] + c_time[next]);

			if (!indegree[next])
				q.push(next);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int s, i_count = 0;
		cin >> c_time[i] >> s;

		while (s != -1) {
			pre_class[s].push_back(i);
			i_count++;
			cin >> s;
		}
		indegree[i] = i_count;

		if (!i_count) {
			ans[i] = c_time[i];
			q.push(i);
		}
	}

	solve();

	return 0;
}