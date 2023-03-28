#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

void solve(int n) {
	
	int ans = 0, count = 1;
	
	sort(arr, arr + n);
	
	for(int i = 0; i < n; ++i) {
		if(arr[i] <= count) {
			ans += 1;
			count = 1;
		}
		else 
			count += 1;
	}
	
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
		
	solve(n);
	
	return 0;
}
