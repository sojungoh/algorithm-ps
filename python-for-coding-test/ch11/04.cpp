#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];

void solve(int n) {
	
	int num = 1;
	
	sort(arr, arr + n);
	
	for(int i = 0; i < n; ++i) {
		
		if(arr[i] > num)
			break;
		
		num += arr[i];
	}
	
	cout << num << endl;
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
