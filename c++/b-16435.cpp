#include <iostream>
#include <algorithm>

using namespace std;

int n, l, height[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;

	for (int i = 0; i < n; i++)
		cin >> height[i];

	swap(height[0], height[n - 1]);
	swap(height[0], height[n / 2]);
	sort(height, height + n);

	for (int i = 0; i < n; i++) {
		if (l >= height[i])
			l++;
	}

	cout << l << '\n';

	return 0;
}