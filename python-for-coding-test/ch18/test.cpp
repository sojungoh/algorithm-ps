#include <iostream>

using namespace std;

int n;

void solve(int **parr) {
	
	int graph[n][n];
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			graph[i][j] = *(*(parr + i) + j); 
		}
	}
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << graph[i][j] << ' ' ;
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	int **arr;
	
	arr = new int*[n];
	for(int i = 0; i < n; ++i)
		arr[i] = new int[n];
	
	int count = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			arr[i][j] = count++;
	
	solve(arr);
	
	return 0;
}
