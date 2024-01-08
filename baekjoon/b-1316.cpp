#include <iostream>
#include <string>

using namespace std;

int solve() {
	int count[26] = {0, };
	
	string s;
	cin >> s;
	
	int l = 1;	
	char c = s[0];
	count[c - 'a'] += 1;
	
	while(l < s.size()) {
		if(c != s[l]) {
			if(count[s[l] - 'a'] != 0)
				break;
			c = s[l];
		}
		count[s[l] - 'a'] += 1;
		l++;
	}
	
	if(l == s.size())
		return 1;
	else
		return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, answer = 0;
	
	cin >> n;
	
	while(n--)
		answer += solve();
	
	cout << answer << '\n';
	
	return 0;
}
