#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, a, b, node[10001];
vector<int> ans;

void solve() {
	memset(node, 0, sizeof(node));

	cin >> n;

	int p, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> p >> c;
		node[c] = p;
	}

	cin >> a >> b;

	do {
		int temp = node[a];
		node[a] = 0;
		a = temp;
	} while (a);

	while (node[b])
		b = node[b];

	ans.push_back(b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
		solve();

	for (int a : ans)
		cout << a << '\n';

	return 0;
}