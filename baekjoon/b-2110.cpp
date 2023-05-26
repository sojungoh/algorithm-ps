#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> v;
int n, c;

void binary_search(int start, int end) {
	
	int ans = 0;
	
	while(start <= end) {
		
		int mid = (start + end) / 2;
		
		int count = 1;
		int val = v[0];
		
		for(int i = 1; i < v.size(); ++i) {
			if(val + mid <= v[i]) {
				count += 1;
				val = v[i];
			}
		}
		
		if(count >= c) {
			start = mid + 1;
			ans = mid;
		}
		else {
			end = mid - 1;
		}		
	}
	
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> c;
	
	int in;
	for(int i = 0; i < n; ++i) {
		cin >> in;
		v.push_back(in);
	}
	
	sort(v.begin(), v.end());
	
	binary_search(1, v[n - 1] - v[0]);
	
	return 0;
}
