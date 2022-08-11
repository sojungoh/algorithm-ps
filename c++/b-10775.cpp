#include <iostream>
#include <cmath>

using namespace std;

int g, p, p_gate[100001] = { 0, }, docking[100001] = { 0, };

int find_gate(int x) {
	if (docking[x] != x)
		docking[x] = find_gate(docking[x]);
	return docking[x];
}

void solve() {
	int ans = 0;

	for (int i = 1; i <= g; i++)
		docking[i] = i;

	for (int i = 1; i <= p && i <= g; i++) {
		int gate = find_gate(p_gate[i]);

		if (gate != 0)
			docking[gate] -= 1;
		else {
			ans = i - 1;
			break;
		}
	}

	ans = (ans == 0) ? min(p, g) : ans;

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> g >> p;

	for (int i = 1; i <= p; i++) {
		int g_range;
		cin >> g_range;
		p_gate[i] = g_range;
	}

	solve();

	return 0;
}