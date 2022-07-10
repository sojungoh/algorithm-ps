#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

char a[51], n = 0, ans = 0;

void solve() {
	size_t sz = 0;

	int k = 0, t = 0;

	for (int i = 0; i < sizeof(a); i++) {

		if (a[i] == '-' || a[i] == '+') {
			if (a[sz] == '-') {
				k++;
				if (k % 2) {

				}
				n = -1 * stoi(&a[sz], &sz);
			}
			else
				n += stoi(&a[sz], &sz);
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i = 0;

	do {
		cin >> a[i];
		++i;
	} while (getc(stdin) == ' ');


	return 0;
}