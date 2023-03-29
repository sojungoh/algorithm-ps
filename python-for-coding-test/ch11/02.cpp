#include <iostream>
#include <string>

using namespace std;

void solve(string s) {
	
	int ans = s[0] - '0';
	
	for(size_t i = 1; i < s.length(); ++i) {
		
		int num = s[i] - '0';
		
		if(ans <= 1 || num <= 1)
			ans += num;
		else
			ans *= num;	
	}
	
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string s;
	cin >> s;
	
	solve(s);
	
	return 0;
}
