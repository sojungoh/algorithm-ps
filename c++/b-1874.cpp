#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<char> ans;
stack<int> s;

int main() {
	int n, a, k;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		vec.push_back(a);
	}

	auto iter = vec.begin();

	k = 1;

	while (iter != vec.end()) {	
		if (k > *iter) {
			if (*iter == s.top()) {
				ans.push_back('-');
				s.pop();
			}
			else {
				printf("NO\n");
				return 0;
			}			
		}
		else {
			while (k <= *iter && k <= n) {
				s.push(k);
				k++;
				ans.push_back('+');
			}
			s.pop();
			ans.push_back('-');
		}
		iter++;
	}

	for (int i = 0; i < ans.size(); i++)
		printf("%c\n", ans[i]);

	return 0;
}