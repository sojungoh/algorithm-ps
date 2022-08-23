#include <iostream>
#include <queue>

using namespace std;

int memo[30001];
queue<int> q;

// bottom-up

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int x;
	cin >> x;

	fill(memo, memo + 30000, 0);

	//solve(x);

	q.push(x);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == 1)
			break;

		if (curr < 1) continue;

		if (curr % 5 == 0) {
			if (memo[curr / 5]) continue;

			memo[curr / 5] = memo[curr] + 1;
			q.push(curr / 5);
		}

		if (curr % 3 == 0) {
			if (memo[curr / 3]) continue;

			memo[curr / 3] = memo[curr] + 1;
			q.push(curr / 3);
		}

		if (curr % 2 == 0) {
			if (memo[curr / 2]) continue;

			memo[curr / 2] = memo[curr] + 1;
			q.push(curr / 2);
		}

		if (memo[curr - 1]) continue;
		memo[curr - 1] = memo[curr] + 1;
		q.push(curr - 1);
	}

	cout << memo[1] << '\n';

	return 0;
}


// top_down

void solve(int x) {
	if (x == 1)
		return;

	if (x % 5 == 0) {
		if (!memo[x / 5] || memo[x / 5] > memo[x] + 1) {
			memo[x / 5] = memo[x] + 1;
			solve(x / 5);
		}
	}

	if (x % 3 == 0) {
		if (!memo[x / 3] || memo[x / 3] > memo[x] + 1) {
			memo[x / 3] = memo[x] + 1;
			solve(x / 3);
		}
	}

	if (x % 2 == 0) {
		if (!memo[x / 2] || memo[x / 2] > memo[x] + 1) {
			memo[x / 2] = memo[x] + 1;
			solve(x / 2);
		}
	}

	if (!memo[x - 1] || memo[x - 1] > memo[x] + 1) {
		memo[x - 1] = memo[x] + 1;
		solve(x - 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int x;
	cin >> x;

	solve(x);

	cout << memo[1] << '\n';

	return 0;
}