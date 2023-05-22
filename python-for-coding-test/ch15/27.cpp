#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;
int max_idx, min_idx;
vector<int> v;

void binary_search(int start, int end) {
	
	if(start > end)
		return;
	
	int mid = (start + end) / 2;
	
	if(v[mid] == x) {
		max_idx = max(max_idx, mid);
		min_idx = min(min_idx, mid);
		
		binary_search(start, mid - 1);
		binary_search(mid + 1, end);
	}
	else if(v[mid] < x) {
		binary_search(mid + 1, end);
	}
	else {
		binary_search(start, mid - 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> x;
	
	max_idx = 0; 
	min_idx = n;
	
	int in;
	for(int i = 0; i < n; ++i) {
		cin >> in;
		v.push_back(in);
	}
	
	binary_search(0, n - 1);
	
	if(max_idx < min_idx)
		cout << -1 << '\n';
	else
		cout << max_idx - min_idx + 1 << '\n';
	
	return 0;
}
