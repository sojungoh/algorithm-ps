#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(vector<int> a, int target, int start, int end) {
	
	while(start <= end) {
		int mid = (start + end) / 2;
		
		if(target == a[mid])
			return true;
		
		if(target < a[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m, in;
	vector<int> a, b;
	
	cin >> n;
	
	for(int i = 0; i < n; ++i) {
		cin >> in;
		a.push_back(in);
	}
	
	cin >> m;
	
	for(int i = 0; i < m; ++i) {
		cin >> in;
		b.push_back(in);
	}
	
	sort(a.begin(), a.end());
	
	for(int x : b) {
		bool flag = binary_search(a, x, 0, a.size() - 1);
		
		if(flag)
			cout << "yes ";
		else
			cout << "no ";
	}
	cout << '\n';
	
	return 0;
}
