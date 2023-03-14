#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s;

	ans = s[0] - '0';

	for (int i = 1; i < s.size(); i++) {
		int n = s[i] - '0';

		if (ans < 2 || n < 2)
			ans += n;
		else
			ans *= n;
	}

	cout << ans << '\n';

	return 0;
}