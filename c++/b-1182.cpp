#include <iostream>
#include <vector>

using namespace std;

int n, s, visit[20], ans = 0, sum_count = 0;
vector<int> num;

void solve(int idx, int end, int sum) {
	if (sum_count == end) {
		if (sum == s) ++ans;
		return;
	}

	for (int curr = idx; curr < n; curr++) {
		if (visit[curr]) continue;

		visit[curr] = 1;
		sum += num[curr];
		++sum_count;

		solve(curr + 1, end, sum);
		
		visit[curr] = 0;
		sum -= num[curr];
		--sum_count;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		num.push_back(input);
	}

	for (int i = 1; i <= n; i++)
		solve(0, i, 0);

	cout << ans << '\n';

	return 0;
}