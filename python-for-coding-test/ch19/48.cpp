#include <iostream>
#include <vector>

using namespace std;

int n, m, k;

struct Info {
	int shark_no;
	int time;
	
	Info(int no, int t):
		shark_no(no), time(t)
	{};
};

vector<vector<Info>> graph(20);
int shark[21][3];
int dx[21][4][4];
int dy[21][4][4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	
	int in;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> in;
			
			if(in == 0)
				graph[i][j].push_back(Info(0, 0));
			else {
				graph[i][j].push_back(Info(in, k));
				shark[in][0] = i;
				shark[in][1] = j;
			}
		}
	}
	
	for(int i = 1; i <= m; ++i)
		cin >> shark[i][2];
	
	for(int i = 1; i <= m; ++i) {
		// u d l r
		for(int j = 0; j < 4; ++j) {
		}
	}
	
	
	
	return 0;
}
