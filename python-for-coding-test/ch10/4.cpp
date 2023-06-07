#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int * time_arr, * indegree;
vector<vector<int>> graph(501);

void topology_sort(int n) {
	
	queue<int> q;
	int *max_time = new int[n + 1];
	fill(max_time, max_time + n + 1, 0);
	
	for(int i = 1; i <= n; ++i) {
		if(indegree[i] == 0) {
			q.push(i);
			max_time[i] = time_arr[i];
		}
	}
				
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		
		for(int next : graph[curr]) {
			max_time[next] = max(max_time[next], max_time[curr] + time_arr[next]);
			indegree[next] -= 1;
			
			if(indegree[next] == 0)
				q.push(next);
		}
	}
	
	for(int i = 1; i <= n; ++i)
		cout << max_time[i] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	time_arr = new int[n + 1];
	indegree = new int[n + 1];
	fill(indegree, indegree + n + 1, 0);
	
	int in;
	for(int i = 1; i <= n; ++i) {
		cin >> time_arr[i];
		
		while(true) {
			cin >> in;
			
			if(in == -1)
				break;
			
			indegree[i] += 1;
			graph[in].push_back(i);
		}
	}
	
	topology_sort(n);
	
	return 0;
}
