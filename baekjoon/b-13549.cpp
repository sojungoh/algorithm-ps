#include <iostream>
#include <queue>

using namespace std;

int n, k, dist[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	queue<int> q;

	cin >> n >> k;

	for (int i = 0; i < 100001; i++)
		dist[i] = int(1e9);

	dist[n] = 0;

	if (n != k) q.push(n);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		int a = curr * 2, b = curr - 1, c = curr + 1;

		if (0 <= a && a < 100001) {
			if (dist[curr] < dist[a]) {
				dist[a] = dist[curr];
				if (a == k) break;
				q.push(a);
			}
		}

		if (0 <= b && b < 100001) {
			if (dist[curr] + 1 < dist[b]) {
				dist[b] = dist[curr] + 1;
				if (b == k) break;
				q.push(b);
			}
		}

		if (0 <= c && c < 100001) {
			if (dist[curr] + 1 < dist[c]) {
				dist[c] = dist[curr] + 1;
				if (c == k) break;
				q.push(c);
			}
		}
	}
	
	cout << dist[k] << '\n';

	return 0;
}