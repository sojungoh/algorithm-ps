#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, score[100000][3];
vector<string> name;

void solve() {
	
	for(int i = 1; i < n; ++i) {
		for(int j = i; j >= 0; --j) {
			if(score[j][0] < score[j - 1][0])
				break;
			
			if(score[j][0] > score[j - 1][0]) {
				for(int k = 0; k < 3; ++k) {
					int temp = score[j][k];
					score[j][k] = score[j - 1][k];
					score[j - 1][k] = temp;
				}
				
				string s = name[j];
				name[j] = name[j - 1];
				name[j - 1] = s;
				
				continue;
			}
			
			if(score[j][1] > score[j - 1][1])
				continue;
			
			if(score[j][1] < score[j - 1][1]) {
				for(int k = 0; k < 3; ++k) {
					int temp = score[j][k];
					score[j][k] = score[j - 1][k];
					score[j - 1][k] = temp;
				}
				
				string s = name[j];
				name[j] = name[j - 1];
				name[j - 1] = s;
				
				continue;
			}
			
			if(score[j][2] < score[j - 1][2])
				continue;
			
			if(score[j][2] > score[j - 1][2]) {
				for(int k = 0; k < 3; ++k) {
					int temp = score[j][k];
					score[j][k] = score[j - 1][k];
					score[j - 1][k] = temp;
				}
				
				string s = name[j];
				name[j] = name[j - 1];
				name[j - 1] = s;
				
				continue;
			}
			
			if(name[j] > name[j - 1])
				continue;
			
			for(int k = 0; k < 3; ++k) {
				int temp = score[j][k];
				score[j][k] = score[j - 1][k];
				score[j - 1][k] = temp;
			}
			
			string s = name[j];
			name[j] = name[j - 1];
			name[j - 1] = s;
		}
	}
	
	for(string s : name)
		cout << s << endl;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	string s;
	for(int i = 0; i < n; ++i) {
		cin >> s >> score[i][0] >> score[i][1] >> score[i][2];
		name.push_back(s);
	}
	
	solve();
		
	return 0;
}
