#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int binary_search(int start, int end) {
	
	while(start <= end) {
		int mid = (start + end) / 2;
		
		if(mid == v[mid])
			return mid;
		
		if(mid > v[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int in;
	for(int i = 0; i < n; ++i) {
		cin >> in;
		v.push_back(in);
	}
	
	cout << binary_search(0, n - 1) << '\n';
	
	return 0;
}
