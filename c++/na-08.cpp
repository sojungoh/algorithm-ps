#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int sum = 0;
	string s, ans = "";

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		int n = s[i] - '0';

		if (0 <= n && n <= 9)
			sum += n;
		else
			ans += s[i];
	}
	sort(ans.begin(), ans.end());

	cout << ans << sum << '\n';

	return 0;
}