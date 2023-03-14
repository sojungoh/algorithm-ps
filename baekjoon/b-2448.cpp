#include <iostream>
#include <algorithm>

using namespace std;

// max row: 3*2^10 , max col: 3*2^11 - 1
char arr[3072][6143];

void star(int row, int col) {
	
	arr[row][col] = '*';
	arr[row + 1][col - 1] = '*';
	arr[row + 1][col + 1] = '*';

	for (int i = -2; i < 3; i++)
		arr[row + 2][col + i] = '*';
}

void solve(int len, int row, int col) {

	if (len == 3) {
		star(row, col);
		return;
	}

	solve(len / 2, row, col);
	solve(len / 2, row + len / 2, col - len / 2);
	solve(len / 2, row + len / 2, col + len / 2);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2 * n - 1; j++)
			arr[i][j] = ' ';
	
	solve(n, 0, n - 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++)
			cout << arr[i][j];
		cout << '\n';
	}

	return 0;
}