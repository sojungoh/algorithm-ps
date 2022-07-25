#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, ans = 0;
vector<vector<int>> relation(101);
queue<int> q;

int bfs(int idx) {
	int sum = 0, depth[101] = { 0, };

	while (!q.empty()) {
		int curr_user = q.front();
		q.pop();

		for (int i = 0; i < relation[curr_user].size(); i++) {
			int next_user = relation[curr_user][i];
			if (idx == next_user || depth[next_user]) continue;
			depth[next_user] = depth[curr_user] + 1;
			q.push(next_user);
		}
	}

	for (int i = 1; i <= n; i++)
		sum += depth[i];

	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		relation[a].push_back(b);
		relation[b].push_back(a);
	}

	int cmp_num, min_num = 2147483647;
	for (int i = 1; i <= n; i++) {
		q.push(i);
		
		cmp_num = bfs(i);

		if (cmp_num < min_num) {
			ans = i;
			min_num = cmp_num;
		}
	}

	cout << ans << '\n';

	return 0;
}