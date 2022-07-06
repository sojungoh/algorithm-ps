#define _CRT_SECURE_NO_WARNINGS
#define p pair<int, int>

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const p& curr, const p& next) {
	if (curr.second == next.second) return curr.first < next.first;
	return curr.second < next.second;
}

int main() {
	int num, start_time, end_time, count;

	vector<p> conf;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d %d", &start_time, &end_time);
		conf.push_back(make_pair(start_time, end_time));
	}

	sort(conf.begin(), conf.end(), cmp);

	auto iter = conf.begin();

	if (iter == conf.end())
		count = 0;
	else {
		count = 1;
		end_time = iter->second;
		iter++;

		while (iter != conf.end()) {
			if (end_time <= iter->first) {
				count += 1;
				end_time = iter->second;
			}
			iter++;		
		}
	}
	cout << count << endl;

	return 0;
}
