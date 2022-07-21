#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
int n, visit[9] = { 0, };

void permutation() {
	if (num.size() == n) {
		for (int i = 0; i < n; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;

		num.push_back(i);
		visit[i] = 1;
		permutation();
		visit[i] = 0;
		num.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	permutation();

	return 0;
}