#include <iostream>
#include <set>

using namespace std;

set<int> s;

void binary_search(int start, int end) {
	
	while(start >= end) {
		
		int mid = (start + end) / 2;
		
		if(s.find(mid) != s.end()) {
			
			
			
		}
		
		
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, c;
	cin >> n >> c;
	
	int in;
	for(int i = 0; i < n; ++i) {
		cin >> in;
		s.push(in);
	}
	
	binary_search(0, n - 1);
	
	return 0;
}
