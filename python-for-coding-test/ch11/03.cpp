#include <iostream>
#include <string>

using namespace std;

void solve(string s) {
	
	int ans = 0, num = s[0] - '0';
	
	for(size_t i = 1; i < s.length(); ++i)
		if(num != s[i] - '0' && s[i - 1] != s[i])
			ans += 1;
	
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
