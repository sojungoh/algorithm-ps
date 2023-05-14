#include <iostream>
#include <vector>

using namespace std;

vector<int> length;

int get_cake_length(int height) {
	int ret_val = 0;
	
	for(int i : length)
		if(i > height)
			ret_val += (i - height);
	
	return ret_val;
}

int binary_search(int m, int start, int end) {
	
	int result = 0;
	
	while(start <= end) {
		
		int mid = (start + end) / 2;
		int cmp = get_cake_length(mid);
		
		if(cmp < m)
			end = mid - 1;
		else {
			start = mid + 1;
			result = mid;
		}
	}
	
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m, max = 0;
	cin >> n >> m;
	
	int l;
	for(int i = 0; i < n; ++i) {
		cin >> l;
		length.push_back(l);
		if(max < l)
			max = l;
	}
		
	cout << binary_search(m, 0, max) << '\n';
	
	return 0;
}
