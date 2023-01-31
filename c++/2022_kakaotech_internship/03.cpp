#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int dp[151][151];
map<pii, int> p; // alp_req, cop_req, idx

int solution(int alp, int cop, vector<vector<int>> problems) {
	int answer = 0;
	unsigned long p_count = 0;
	
	// initialization
	for(int i = 0; i <= 150; ++i) {
		for(int j = 0; j <= 150; ++j) {
			if(i == alp && j == cop) dp[i][j] = 0;
			else dp[i][j] = 1e9;
		}
	}
	
	for(unsigned long i = 0; i < problems.size(); ++i) {
		p.insert({{problems[i][0], problems[i][1]}, i});
	}
	
	// dp
	for(int i = 0; i <= 150; ++i) {
		for(int j = 0; j <= 150; ++j) {
			
			if(p.find({i, j}) != p.end()) {
				int idx = p[{i, j}];
				int exp_alp = i + problems[idx][2];
				int exp_cop = j + problems[idx][3];
				int cost = problems[idx][4];
				dp[exp_alp][exp_cop] = min(dp[exp_alp][exp_cop], dp[i][j] + cost);
				
				++p_count;
				if(p_count == problems.size()) {
					answer = dp[exp_alp][exp_cop];
					break;
				}
			}
			else {
				if(i < alp || j < cop) continue;
				else dp[i][j] = min(dp[i][j], dp[i - alp][j - cop] + i - alp + j - cop);
			}
		}
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	vector<vector<int>> problems = {{10, 15, 2, 1, 2}, {20, 20, 3, 3, 4}};
	
	cout << solution(10, 10, problems) << '\n';
	
	return 0;
}
