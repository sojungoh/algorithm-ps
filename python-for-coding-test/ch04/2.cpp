#include <iostream>
#include <string>

using namespace std;

int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; // n w s e

void solve(string s) {
		
	int x, y, ans = 0;
	int col = s[0] - 96;
	int row = s[1] - '0';
	
	for(int i = 0; i < 4; ++i) {
		x = col + dx[i] * 2;
		y = row + dy[i] * 2;
			
		for(int j = 0; j < 2; ++j) {
			if(i % 2 == 0)
				x += dx[2*j + 1];
			else
				y += dy[2*j];
			
			if(x < 1 || y < 1 || x > 8 || y > 8)
				continue;
			
			ans += 1;
		}
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
