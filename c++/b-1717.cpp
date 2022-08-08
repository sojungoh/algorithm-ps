#include <iostream>

using namespace std;

int n, m, query[1000001][3], p_team[1000001];

int find_team(int x) {
	if (p_team[x] != x)
		p_team[x] = find_team(p_team[x]);
	
	return p_team[x];
}

void union_team(int a, int b) {
	a = find_team(a);
	b = find_team(b);

	if (a < b)
		p_team[b] = a;
	else
		p_team[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int q, a, b;
		cin >> q >> a >> b;
		query[i][0] = q;
		query[i][1] = a;
		query[i][2] = b;
	}

	for (int i = 0; i <= n; i++)
		p_team[i] = i;

	for (int i = 0; i < m; i++) {
		if (query[i][0] == 0) {
			union_team(query[i][1], query[i][2]);
		}
		else if (query[i][0] == 1) {
			int team_a = find_team(query[i][1]);
			int team_b = find_team(query[i][2]);

			if (team_a == team_b)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return 0;
}
