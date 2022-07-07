#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<bool> broken(10, false);
vector<int> chan_vec;

int main() {
	int chan, broken_num, button;
	int temp, digit = 0;
	int *iter;
	int up_button, down_button, up, down;
	up_button = down_button = up = down = 0;
	int click_count, ans;
	
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
	if (broken_num == 10) {
		printf("%d\n", abs(chan - 100));
		return 0;
	}
	if (broken_num == 9 && !broken[0]) {
		printf("%d\n", min(abs(chan - 100), chan + 1));
		return 0;
	}

	temp = chan;
	do {
		chan_vec.push_back(temp % 10);
		digit++;
		temp /= 10;
	} while (temp != 0);

	iter = &chan_vec[0];
	for (int i = 0; i < digit; iter++, i++) {
		if (i != 0 && down > *(iter - 1)) {
			if (*iter != 0)
				down = *iter - 1;
			up = *iter;
		}
		else if (i != 0 && up < *(iter - 1)) {
			if (*iter != 9)
				up = *iter + 1;
			down = *iter;
		}
		else up = down = *iter;

		if (down == 0)
			if (i == 0 || broken[0])
				down = 9;

		while (down >= 0) {
			if (!broken[down]) break;
			if (down == 0) down = 9;
			down--;
		}

		if (up == 9)
			if (i == 0 || broken[9])
				up = 0;

		while (up <= 9) {
			if (!broken[up]) break;
			if (up == 10) up = 0;
			up++;
		}
		up_button += pow(10, i) * up;
		down_button += pow(10, i) * down;
	}
	//cout << up_button << " " << down_button << endl;
	printf("%d %d\n", up_button, down_button);
	click_count = min(abs(up_button - chan), abs(chan - down_button));
	ans = min(click_count + digit, abs(chan - 100));

	printf("%d\n", ans);

	return 0;
}
