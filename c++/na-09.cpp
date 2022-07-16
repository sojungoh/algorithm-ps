#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// aabbaccc -> 0: 8磊府 / 1: 2a2ba3c, 7磊府 / 2: 8磊府
// abcabcdedede -> 0: 12磊府 / 1: 12磊府 / 2: abcabc3de, 9磊府 / 3: 2abcdedede, 10磊府
// abcabcdede -> 0: 8磊府 / 1: 8磊府 / 2: abcabc2de, 9磊府 / 3: 2abcdede, 8磊府
// ababcdcdababcdcd -> 0: 16磊府 / 1: 16磊府 / 2: 2ab2cd2ab2cd, 12磊府 / 8: 2ababcdcd, 9磊府

// abcabcdede -> 1: abcabcdede / 2: abcabc2de / 3: 2abcdede
// abcdedeabc -> 2: abc2deabc

// abcabcabcdede -> 3: 3abcdede

int solution(string s) {
	int answer = 0;
	answer = s.size();
	string repeat;

	for (int i = 1; i <= s.size() / 2; i++) {
		repeat = s.substr(0, i);
		int temp = 0, j = i, flag = 0;

		for (; j <= s.size() - i; j += i) {
			if (repeat == s.substr(j, i)) {
				flag = 1;
				continue;
			}
			if (flag) temp += i + 1;
			else temp += i;

			repeat = s.substr(j, i);
			flag = 0;
		}
		if (flag) temp += i + 1;
		else temp += i + s.size() - j;

		answer = min(answer, temp);
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	cout << solution(s) << '\n';

	return 0;
}