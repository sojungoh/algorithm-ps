#include <iostream>
#include <algorithm>

using namespace std;

int n, a[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	int sum = 0, k = 0;
	
	while (n != k) {
		if (sum + 1 < a[k])
			break;

		sum += a[k];
		k++;
	}
	cout << sum + 1 << '\n';

	return 0;
}

// 1 1 2 3 9 -> 8
// 1 1 2 3 8 -> 16
// 2 3 4 5 -> 1