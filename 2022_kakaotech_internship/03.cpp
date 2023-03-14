#include <bits/stdc++.h>
using namespace std;

int dp[181][181];

int solution(int alp, int cop, vector<vector<int>> problems) {
	int answer = 0, max_alp = 0, max_cop = 0;
	
	// find the largest alp and cop
	for(vector<int> vec : problems) {
		max_alp = max(max_alp, vec[0]);
		max_cop = max(max_cop, vec[1]);
	}
	
	alp = min(alp, max_alp);
	cop = min(cop, max_cop);
	
	// initalize dp array
	for(int i = 0; i <= 180; ++i) {
		for(int j = 0; j <= 180; ++j) {
			if (i <= alp && j <= cop) dp[i][j] = 0;
			else dp[i][j] = 1e9;
		}
	}
	
	// dp
	int alp_req, cop_req, alp_rwd, cop_rwd, cost;
	int alp_idx, cop_idx;
	
	for(int i = alp; i <= max_alp; ++i) {
		for(int j = cop; j <= max_cop; ++j) {
			
			alp_idx = min(i + 1, max_alp);
			cop_idx = min(j + 1, max_cop);
			dp[alp_idx][j] = min(dp[alp_idx][j], dp[i][j] + 1);
			dp[i][cop_idx] = min(dp[i][cop_idx], dp[i][j] + 1);
			
			for(unsigned long k = 0; k < problems.size(); ++k) {
				alp_req = problems[k][0];
				cop_req = problems[k][1];
				alp_rwd = problems[k][2];
				cop_rwd = problems[k][3];
				cost = problems[k][4];
				
				if(i < alp_req || j < cop_req) continue;
				
				alp_idx = min(i + alp_rwd, max_alp);
				cop_idx = min(j + cop_rwd, max_cop);
				dp[alp_idx][cop_idx] = min(dp[alp_idx][cop_idx], dp[i][j] + cost);	
			}
		}
	}
	
	answer = dp[max_alp][max_cop];
	
	return answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	vector<vector<int>> problems = {{10, 15, 2, 1, 2}, {20, 20, 3, 3, 4}};
		
	cout << solution(20, 20, problems) << '\n';
	
	//for(int i = 0; i <= 10; ++i) {
		//for(int j = 0; j <= 11; ++j) {
			//cout << dp[i][j] << ' ';
		//}
		//cout << '\n';
	//}
	
	return 0;
}
