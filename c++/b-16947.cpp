#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> edge_check;
vector<bool> first_check;
vector<bool> visit_check;

int count_dist;
int is_found;

int find_circle(int n, int curr, int next) {
	for (int i = 0; i < n; i++) {
		if (edge_check[next][i] && i != curr) {
			if (first_check[next])
				return next;

			first_check[next] = true;
			return find_circle(n, next, i);
		}
	}
}

void dfs(int n, int v, int goal) {
	count_dist = 0;
	is_found = 0;
	visit_check[v] = true;

	for (int i = 0; i < n; i++) {
		if (edge_check[v][i] && !visit_check[v]) {
			if (i == goal) {
				is_found = 1; 
				break;
			}
			else 
				dfs(n, i, goal);
		}
		if (is_found == 1)
			count_dist++;
	}
}

int main() {
	int n, s1, s2;

	scanf("%d", &n);

	edge_check.assign(n,vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s1, &s2);
		s1 -= 1; s2 -= 1;
		edge_check[s1][s2] = 1;
		edge_check[s2][s1] = 1;
	}

	for (int station = 0; station < n; station++) {
		int i = 0;
		first_check.assign(n, false);

		while (!edge_check[station][i]) i++;
		first_check[station] = true;
		int temp = find_circle(n, station, i);

		visit_check.assign(n, 0);
		dfs(n, temp, station);

		cout << count_dist << " ";
	}
	cout << endl;
	return 0;
}