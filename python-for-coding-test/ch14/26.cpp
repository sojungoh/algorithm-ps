#include <iostream>

using namespace std;

int count[1001] = {0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, ans = 0;
	
	cin >> n;
	
	int a;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		count[a] += 1;
	}
	
	int sum = 0;
	for(int i = 0; i <= 1000; ++i) {
		if(count[i] == 0)
			continue;
		
		int num = count[i];
		
		while(num > 0) {
			if(!sum) {
				sum = i;
				num -= 1;
				continue;
			}
			
			num -= 1;
			sum += i;
			ans += sum;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
