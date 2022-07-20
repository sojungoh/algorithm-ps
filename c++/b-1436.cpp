#include <iostream>
#include <string>

using namespace std;

string title;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	string title = "";

	int idx = 0;
	for (int i = 666; i <= 66666666; i++) {
		title = to_string(i);
		while (idx != title.size() - 2) {
			if (title.substr(idx, 3) == "666") {
				--n;
				break;
			}
			++idx;
		}
		idx = 0;
		if (!n) break;
	}

	cout << title << '\n';

	return 0;
}