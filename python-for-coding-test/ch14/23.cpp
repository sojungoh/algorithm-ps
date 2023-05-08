#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, score[100000][3];
vector<string> name;

void sort_by_score(vector<int> v, int order) {
	
	if(order == 3) {
		vector<string> s3;
		
		for(int idx : v)
			s3.push_back(name[idx]);
		
		sort(s3.begin(), s3.end());
		
		for(string s : s3)
			cout << s << endl;
		
		return;
	}
	
	vector<vector<int>> s(101);
	
	for(int idx : v)
		s[score[idx][order]].push_back(idx);
	
	if(order == 1) {
		for(int i = 1; i <= 100; ++i) {
			if(s[i].size() == 0)
				continue;
			
			if(s[i].size() == 1)
				cout << name[i] << endl;
			else
				sort_by_score(s[i], order + 1);
		}
	}
	else {
		for(int i = 100; i > 0; --i) {
			if(s[i].size() == 0)
				continue;
			
			if(s[i].size() == 1)
				cout << name[i] << endl;
			else
				sort_by_score(s[i], order + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	vector<vector<int>> s1(101);
	string s;
	
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> s >> score[i][0] >> score[i][1] >> score[i][2];
		name.push_back(s);
		s1[score[i][0]].push_back(i);
	}
	
	for(int i = 100; i > 0; --i) {
		if(s1[i].size() == 0)
			continue;
		
		if(s1[i].size() == 1)
			cout << name[i] << endl;
		else
			sort_by_score(s1[i], 1);
	}
		
	return 0;
}
