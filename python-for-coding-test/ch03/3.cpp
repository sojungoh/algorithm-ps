#include <iostream>
#include <cmath>

using namespace std;

int arr[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	int min_val = 10001;
	int max_val = 0;
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i) {
		min_val = 10001;
		for(int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
			min_val = min(min_val, arr[i][j]);
		}
		max_val = max(max_val, min_val);
	}
			
	cout << max_val << endl;
	
	return 0;
}
