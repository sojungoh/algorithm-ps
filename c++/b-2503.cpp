#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, pair<int, int>>> guess;

int ball_check(string a, string b) {
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			if (a[i] == b[j]) count++;
		}
	}
	return count;
}

void solve() {
	int ans = 0;

	for (int n = 123; n < 988; n++) {
		if (n % 10 == 0 || (n / 10) % 10 == 0) continue;

		string cmp = to_string(n);

		if (ball_check(cmp, cmp)) continue;

		int i = 0;
		for (; i < guess.size(); i++) {
			string num = to_string(guess[i].first);
			int strike = guess[i].second.first, ball = guess[i].second.second;

			int s_count = 0;
			for (int j = 0; j < 3; j++) {
				if (num[j] == cmp[j]) s_count++;
			}
			int b_count = ball_check(num, cmp);

			if (s_count != strike || b_count != ball) break;
		}
		if (i == guess.size()) ans += 1;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, a, b, c;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		guess.push_back(make_pair(a, make_pair(b, c)));
	}

	solve();

	return 0;
}