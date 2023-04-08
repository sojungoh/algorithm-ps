#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> alphabets;

void solve(string s) {
	
	int sum_of_numbers = 0;
	
	
	for(size_t i = 0; i < s.length() ; ++i) {
		if(0 <= s[i] - '0' && s[i] - '0' <= 9)
			sum_of_numbers += s[i] - '0';
		else
			alphabets.push_back(s[i]);
	}
	
	sort(alphabets.begin(), alphabets.end());
	
	for(size_t i = 0; i < alphabets.size(); ++i)
		cout << alphabets[i];
	
	cout << sum_of_numbers << endl;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string s;
	cin >> s;
	
	solve(s);
	
	return 0;
}
