#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x = 0;

void solve() {
	int num, s;
	vector<int> score;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> s;
		score.push_back(s);
	}

	sort(score.begin(), score.end());

	int gap = 0;
	for (int i = 0; i < score.size() - 1; i++) {
		if (gap < score[i + 1] - score[i])
			gap = score[i + 1] - score[i];
	}

	++x;
	cout << "Class " << x << '\n';
	cout << "Max " << score[num - 1] << ", ";
	cout << "Min " << score[0] << ", ";
	cout << "Largest gap " << gap << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
		solve();

	return 0;
}