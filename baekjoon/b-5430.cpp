#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solve() {
	int n;
	string p, s;
	
	cin >> p >> n >> s;

	int *arr = new int[n];
	char sep = ',';	
	int curr = 1, count = 0;
	size_t idx = s.find(sep, curr);
	
	while(idx != string::npos) {
		arr[count++] = stoi(s.substr(curr, idx-curr));
		curr = idx + 1;
		idx = s.find(sep, curr);
	}
	
	if(n != 0)
		arr[count] = stoi(s.substr(curr, s.length() - curr - 1));
	
	int start = 0, end = n - 1, d_cnt = 0;
	size_t p_sz = p.length();
	
	for(int i = 0; i < p_sz; ++i) {
		if(p[i] == 'R')
			swap(start, end);
		else if(p[i] == 'D') {
			d_cnt += 1;
			
			if(d_cnt != n) {	
				if(start <= end)
					start += 1;
				else
					start -= 1;
			}
			
			if(start >= n || start < 0)
				return "error";
		}
	}
	
	string ans = "[";
	int t = (start <= end) ? 1 : -1;
	
	if(d_cnt != n) {
		while(start != end) {
			ans += to_string(arr[start]);
			ans += ',';
			start += t;
		}
		ans += to_string(arr[start]);
	}
	
	ans += ']';
	
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--)
		cout << solve() << '\n';
	
	return 0;
}
