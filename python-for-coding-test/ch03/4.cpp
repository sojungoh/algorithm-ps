#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, k, ans = 0;
	cin >> n >> k;
	
	while(n != 1) {
		if(n % k == 0) {
			n /= k;
			ans += 1;
		}
		else {
			n -= 1;
			ans += 1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
