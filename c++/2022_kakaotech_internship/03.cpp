#include <bits/stdc++.h>
using namespace std;

int dp[151][151];

int solution(int alp, int cop, vector<vector<int>> problems) {
	int answer = 0;
	int max_alp = 0, max_cop = 0;
	
	// find the largest alp and cop
	for(vector<int> vec : problems) {
		max_alp = max(max_alp, vec[0]);
		max_cop = max(max_cop, vec[1]);
	}
	
	// init dp array
	for(int i = 0; i <= max_alp; ++i) {
		for(int j = 0; j <= max_cop; ++j) {
			if(i <= alp && j <= cop) dp[i][j] = 0;
			else dp[i][j] = 1e9;
		}
	}
	
	// dp
	int alp_req, cop_req, alp_rwd, cop_rwd, cost;
	
	for(int i = 0; i <= max_alp; ++i) {
		for(int j = 0; j <= max_cop; ++j) {
			
			if(alp <= i && cop <= j)
				dp[i][j] = min(dp[i][j], dp[alp][cop] + (i - alp) + (j - cop));
			
			for(unsigned long k = 0; k < problems.size(); ++k) {
				alp_req = problems[k][0];
				cop_req = problems[k][1];
				alp_rwd = problems[k][2];
				cop_rwd = problems[k][3];
				cost = problems[k][4];
				
				if(i < alp_req || j < cop_req) continue;
				else dp[i + alp_rwd][j + cop_rwd] = min(dp[i + alp_rwd][j + cop_rwd], dp[i][j] + cost);	
			}
		}
	}
	
	answer = dp[max_alp][max_cop];
	
	return answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	vector<vector<int>> problems = {{0, 0, 2, 1, 2}, {4, 5, 3, 1, 2}, 
									{4, 11, 4, 0, 2}, {10, 4, 0, 4, 2}};
	
	cout << solution(0, 0, problems) << '\n';
	
	for(int i = 0; i <= 10; ++i) {
		for(int j = 0; j <= 11; ++j) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
