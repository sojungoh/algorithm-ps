#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, score[100000][3];
vector<string> name;
vector<string> ans;

void sort_by_score(vector<int> v, int order) {
	
	if(order == 3) {
		vector<string> name_vec;
		
		for(int idx : v)
			name_vec.push_back(name[idx]);
		
		sort(name_vec.begin(), name_vec.end());
		
		for(string s : name_vec)
			ans.push_back(s);
		
		return;
	}
	
	vector<vector<int>> sort_vec(101);
	
	for(int idx : v)
		sort_vec[score[idx][order]].push_back(idx);
	
	if(order == 1) {
		for(int i = 1; i <= 100; ++i) {
			if(sort_vec[i].size() == 0)
				continue;
			
			if(sort_vec[i].size() == 1)
				ans.push_back(name[sort_vec[i][0]]);
			else
				sort_by_score(sort_vec[i], order + 1);
		}
	}
	else {
		for(int i = 100; i > 0; --i) {
			if(sort_vec[i].size() == 0)
				continue;
			
			if(sort_vec[i].size() == 1)
				ans.push_back(name[sort_vec[i][0]]);
			else
				sort_by_score(sort_vec[i], order + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	vector<vector<int>> sort_vec(101);
	string s;
	
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> s >> score[i][0] >> score[i][1] >> score[i][2];
		name.push_back(s);
		sort_vec[score[i][0]].push_back(i);
	}
	
	for(int i = 100; i > 0; --i) {
		if(sort_vec[i].size() == 0)
			continue;
		
		if(sort_vec[i].size() == 1)
			ans.push_back(name[sort_vec[i][0]]);
		else
			sort_by_score(sort_vec[i], 1);
	}
	
	for(string a: ans)
		cout << a << '\n'; //endl -> timeout occurs!!
		 
	return 0;
}
