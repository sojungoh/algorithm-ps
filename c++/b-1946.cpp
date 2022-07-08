#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int, int>

int n;
vector<int> ans;

bool cmp(const pii& p1, const pii& p2) {
	return p1.first < p2.first;
}

void solve() {
	vector<pii> vec;
	int a, b, min, count = 1;
	
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		vec.push_back(pii(a, b));
	}
	sort(vec.begin(), vec.end(), cmp);

	auto iter = vec.begin();
	min = iter->second;
	for (; iter != vec.end(); ++iter) {
		if (min > iter->second) {
			min = iter->second;
			count++;
		}
	}
	ans.push_back(count);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, i = 0;
	cin >> t;

	while (t--) {
		cin >> n;
		solve();
		++i;
	}

	for (int ans : ans)
		cout << ans << "\n";

	return 0;
}