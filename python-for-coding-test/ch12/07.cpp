#include <iostream>

using namespace std;

void solve(int n) {
	int k, count = 1;
	
	k = n;
	
	while(k / 10 != 0) {
		count++;
		k /= 10;
	}
	
	k = 0;
	
	for(int i = 0; i < count / 2; ++i) { 
		k += n % 10;
		n /= 10;
	}
	
	for(int i = count / 2; i < count; ++i) {
		k -= n % 10;
		n /= 10;
	}
	
	if(k == 0)
		cout << "LUCKY" << endl;
	else
		cout << "READY" << endl;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	solve(n);
	
	return 0;
}
