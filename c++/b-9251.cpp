#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve(string a, string b) {
	vector<int> index;

	for (int i = 0; i < a.size(); i++) {
		char c = a[i];

		for (int j = 0; j < b.size(); j++) {
			if (b[j] == c) {
				int idx = upper_bound(index.begin(), index.end(), j) - index.begin();

				if (idx != 0 && index[idx - 1] == j) continue;

				if (idx == index.size()) {
					index.push_back(j);
				}
				else {
					if (index[idx] == j) continue;
					index[idx] = j;
				}

				break;
			}
		}
	}

	for (int i = 0; i < index.size(); i++)
		cout << index[i] << ' ';
	cout << '\n';

	return index.size();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;

	cout << max(solve(a, b), solve(b, a)) << '\n';

	return 0;
}