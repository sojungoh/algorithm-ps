#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string s = to_string(n);
	int sum = 0, sz = s.size();

	for (int i = 0; i < sz; i++) {
		if (i < sz / 2) sum += s[i] - '0';
		else sum -= s[i] - '0';
	}

	if (!sum)
		cout << "LUCKY" << '\n';
	else
		cout << "READY" << '\n';

	return 0;
}
