#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;

int main() {
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);

	cin >> s;

	int i, ans = 0;
	char c = s[0];

	for (i = 1; i < s.size(); i++) {
		if (s[i] == c) continue;

		if(s[i - 1] != s[i])
			ans++;
	}

	cout << ans << '\n';

	return 0;
}