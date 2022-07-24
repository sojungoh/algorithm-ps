#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, num[11], op_idx[10], visited[10], max_num = -1e9, min_num = 1e9;
vector<int> op_perm;

int solve() {
	int res = num[0];

	for (int i = 0; i < n - 1; i++) {
		int j = op_perm[i];

		if (op_idx[j] == 0)
			res += num[i + 1];
		else if (op_idx[j] == 1)
			res -= num[i + 1];
		else if (op_idx[j] == 2)
			res *= num[i + 1];
		else if (op_idx[j] == 3)
			res /= num[i + 1];
	}
	return res;
}

void permutation(int op_count) {
	if (op_count == n - 1) {
		int res = solve();
		max_num = max(max_num, res);
		min_num = min(min_num, res);
		return;
	}

	for (int i = 0; i < n - 1; i++) {
		if (visited[i]) continue;

		op_perm.push_back(i);
		visited[i] = 1;
		permutation(op_count + 1);
		op_perm.pop_back();
		visited[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	int t, idx = 0;
	for (int i = 0; i < 4; i++) {
		cin >> t;
		while (t) {
			op_idx[idx++] = i;
			--t;
		}
	}

	permutation(0);

	cout << max_num << '\n';
	cout << min_num << '\n';

	return 0;
}