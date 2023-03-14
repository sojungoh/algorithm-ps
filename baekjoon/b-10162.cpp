#include <iostream>
#include <algorithm>

using namespace std;

int T, ans[3] = {0, }, button[3] = {300, 60, 10};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	
	int i = 0;

	while (i != 3) {
		if (T >= button[i]) {
			ans[i] = T / button[i];
			T %= button[i];
		}
		i++;
	}

	if (T != 0)
		cout << -1 << '\n';
	else {
		for (int a : ans)
			cout << a << ' ';
		cout << '\n';

	}
	return 0;
}