#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;

void solve() {
	size_t idx;
	int ans = stoi(s, &idx);
	int sub = 0;

	for (int i = idx; i < s.size(); i++) {
		if (s[i] != '+' && s[i] != '-')
			continue;

		if (sub == 0) {
			if (s[i] == '+')
				ans += stoi(&s[i + 1]);
			else if (s[i] == '-')
				sub = stoi(&s[i + 1]);
		}
		else {
			sub += stoi(&s[i + 1]);
		}
	}
	ans -= sub;

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s;

	solve();

	return 0;
}