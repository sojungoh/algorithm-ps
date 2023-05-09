#include <iostream>
#include <vector>

using namespace std;

int count[100001] = {0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int t;
	for(int i = 0; i < n; ++i){
		cin >> t;
		count[t] += 1;
	}
	
	int mid = (n % 2 == 0) ? n / 2 : (n + 1) / 2;
	
	int ans = 0, sum = 0;
	for(int i = 1; i <= 100000; ++i) {
		sum += count[i];
		
		if(sum >= mid) {
			ans = i;
			break;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
