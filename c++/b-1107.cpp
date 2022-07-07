#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

vector<bool> broken(10, false);
vector<int> chan_vec;

bool button_check(int chan) {
	int temp = chan;
	do {
		if (broken[temp % 10])
			return false;
		temp /= 10;
	} while (temp != 0);

	return true;
}

int main() {
	int chan, broken_num, button, min_click, cmp_click;
	string s = "";

	scanf("%d", &chan);
	scanf("%d", &broken_num);

	for (int i = 0; i < broken_num; i++) {
		scanf("%d", &button);
		broken[button] = true;
	}

	if (chan == 100) {
		printf("%d\n", 0);
		return 0;
	}

	min_click = abs(chan - 100);
	for (int i = 0; i < 1000000; i++) {
		if (i % 10 == 0)
			s = to_string(i);

		if (button_check(i)) {
			cmp_click = abs(i - chan) + s.size();
			if (cmp_click < min_click)
				min_click = cmp_click;
		}
	}
	printf("%d", min_click);

	return 0;
}
