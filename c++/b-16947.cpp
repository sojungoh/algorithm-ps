#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, ans[3001] = { 0, };
vector<vector<int>> connect(3001);

int station = 1, visited[3001] = { 0, }, circle = 0;
bool flag = false;

void dfs(int before, int curr) {
	if (visited[curr]) {
		circle = curr;
		return;
	}

	for (int i = 0; i < connect[curr].size(); i++) {
		if (connect[curr][i] == before) continue;

		visited[curr] = 1;
		dfs(curr, connect[curr][i]);
		visited[curr] = 0;

		if (flag) ans[station]++;

		if (circle == curr)
			flag = true;
		
		if(circle != 0)
			break;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	int from, to;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		connect[from].push_back(to);
		connect[to].push_back(from);
	}

	for (; station <= n; station++) {
		dfs(0, station);
		memset(visited, 0, sizeof(visited));
		circle = 0;
		flag = false;
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}