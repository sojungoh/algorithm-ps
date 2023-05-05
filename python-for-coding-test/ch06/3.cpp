#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> v(101);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, score;
	string name;
	
	cin >> n;
	
	for(int i = 0; i < n; ++i) {
		cin >> name >> score;
		v[score].push_back(name);
	}
	
	for(int i = 0; i <= 100; ++i)
		if(v[i].size() != 0)
			for(int j = 0; j < v[i].size(); ++j)
				cout << v[i][j] << ' ';
	cout << endl;
	
	return 0;
}
