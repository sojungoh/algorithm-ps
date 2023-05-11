#include <iostream>

using namespace std;

int count[1001] = {0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	int max = 0, ans = 0;
	
	cin >> n;
	
	int a;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		count[a] += 1;
		if(max < a)
			max = a;
	}
	
	int first = 0, check = 0;
	for(int i = 0; i <= 1000; ++i) {
		int num = count[i];
		
		while(num > 0) {
			if(!first) {
				first = i;
				num -= 1;
				continue;
			}
			
			num -= 1;
			check += 1;
			ans += first + i;
			
			// what if sum overflows 1000?
			if(check != n - 1)
				count[first + i] += 1;
			
			first = 0;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
